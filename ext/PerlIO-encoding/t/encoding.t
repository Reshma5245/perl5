#!./perl -w

BEGIN {
    unless (find PerlIO::Layer 'perlio') {
	print "1..0 # Skip: not perlio\n";
	exit 0;
    }
    unless (eval { require Encode } ) {
	print "1..0 # Skip: not Encode\n";
	exit 0;
    }
}

use Test::More tests => 22;

my $grk = "grk$$";
my $utf = "utf$$";
my $fail1 = "fa$$";
my $fail2 = "fb$$";
my $russki = "koi8r$$";
my $threebyte = "3byte$$";

if (open(GRK, ">$grk")) {
    binmode(GRK, ":bytes");
    # alpha beta gamma in ISO 8859-7
    print GRK "\xe1\xe2\xe3";
    close GRK or die "Could not close: $!";
}

{
    is(open(my $i,'<:encoding(iso-8859-7)',$grk), 1);
    is(open(my $o,'>:utf8',$utf), 1);
    is((print $o readline $i), 1);
    close($o) or die "Could not close: $!";
    close($i);
}

if (open(UTF, "<$utf")) {
    binmode(UTF, ":bytes");
    if (ord('A') == 193) { # EBCDIC
	# alpha beta gamma in UTF-EBCDIC Unicode (0x3b1 0x3b2 0x3b3)
	is(scalar <UTF>, "\xb4\x58\xb4\x59\xb4\x62");
    } else {
	# alpha beta gamma in UTF-8 Unicode (0x3b1 0x3b2 0x3b3)
	is(scalar <UTF>, "\xce\xb1\xce\xb2\xce\xb3");
    }
    close UTF;
}

{
    use Encode;
    is (open(my $i,'<:utf8',$utf), 1);
    is (open(my $o,'>:encoding(iso-8859-7)',$grk), 1);
    is ((scalar print $o readline $i), 1);
    close($o) or die "Could not close: $!";
    close($i);
}

if (open(GRK, "<$grk")) {
    binmode(GRK, ":bytes");
    is(scalar <GRK>, "\xe1\xe2\xe3");
    close GRK;
}

$SIG{__WARN__} = sub {$warn .= $_[0]};

is (open(FAIL, ">:encoding(NoneSuch)", $fail1), undef, 'Open should fail');
like($warn, qr/^Cannot find encoding "NoneSuch" at/);

is(open(RUSSKI, ">$russki"), 1);
print RUSSKI "\x3c\x3f\x78";
close RUSSKI or die "Could not close: $!";
open(RUSSKI, "$russki");
binmode(RUSSKI, ":raw");
my $buf1;
read(RUSSKI, $buf1, 1);
# eof(RUSSKI);
binmode(RUSSKI, ":encoding(koi8-r)");
my $buf2;
read(RUSSKI, $buf2, 1);
my $offset = tell(RUSSKI);
is(ord $buf1, 0x3c);
is(ord $buf2, (ord('A') == 193) ? 0x6f : 0x3f);
is($offset, 2);
close RUSSKI;

undef $warn;

# Check there is no Use of uninitialized value in concatenation (.) warning
# due to the way @latin2iso_num was used to make aliases.
is(open(FAIL, ">:encoding(latin42)", $fail2), undef, 'Open should fail');

like($warn, qr/^Cannot find encoding "latin42" at.*line \d+\.$/);

# Create a string of chars that are 3 bytes in UTF-8 
my $str = "\x{1f80}" x 2048;

# Write them to a file
open(F,'>:utf8',$threebyte) || die "Cannot open $threebyte:$!";
print F $str;
close(F);

# Read file back as UTF-8 
open(F,'<:encoding(utf-8)',$threebyte) || die "Cannot open $threebyte:$!";
my $dstr = <F>;
close(F);
is($dstr, $str);

# Try decoding some bad stuff
open(F,'>:raw',$threebyte) || die "Cannot open $threebyte:$!";
if (ord('A') == 193) { # EBCDIC
    print F "foo\x8c\x80\x80\x80bar\n\x80foo\n";
} else {
    print F "foo\xF0\x80\x80\x80bar\n\x80foo\n";
}
close(F);

open(F,'<:encoding(utf-8)',$threebyte) || die "Cannot open $threebyte:$!";
$dstr = join(":", <F>);
close(F);
if (ord('A') == 193) { # EBCDIC
    is($dstr, "foo\\x8C\\x80\\x80\\x80bar\n:\\x80foo\n");
} else {
    is($dstr, "foo\\xF0\\x80\\x80\\x80bar\n:\\x80foo\n");
}

# Check that PerlIO::encoding can handle custom encodings that do funny
# things with the buffer.
use Encode::Encoding;
package Extensive {
 @ISA = Encode::Encoding;
 __PACKAGE__->Define('extensive');
 sub encode($$;$) {
  my ($self,$buf,$chk) = @_;
  my $leftovers = '';
  if ($buf =~ /(.*\n)(?!\z)/) {
    $buf = $1;
    $leftovers = $';
  }
  if ($chk) {
   my $x = ' ' x 8000;  # prevent realloc from simply extending the buffer
   $_[1] = ' ' x 8000;  # make SvPVX point elsewhere
   $_[1] = $leftovers;
  }
  $buf;
 }
 no warnings 'once'; 
 *decode = *encode;
}
open my $fh, ">:encoding(extensive)", \$buf;
$fh->autoflush;
print $fh "doughnut\n";
print $fh "quaffee\n";
close $fh;
is $buf, "doughnut\nquaffee\n", 'buffer realloc during encoding';
$buf = "Sheila surely shod Sean\nin shoddy shoes.\n";
open $fh, "<:encoding(extensive)", \$buf;
is join("", <$fh>), "Sheila surely shod Sean\nin shoddy shoes.\n",
   'buffer realloc during decoding';

package Globber {
 no warnings 'once';
 @ISA = Encode::Encoding;
 __PACKAGE__->Define('globber');
 sub encode($$;$) {
  my ($self,$buf,$chk) = @_;
  $_[1] = *foo if $chk;
  $buf;
 }
 *decode = *encode;
}

# Here we just want to test there is no crash.  The actual output is not so
# important.
# We need a double eval, as scope unwinding will close the handle,
# which croaks.
eval { eval {
    open my $fh, ">:encoding(globber)", \$buf;
    print $fh "Agathopous Goodfoot\n";
    close $fh;
}; $e = $@};
like $@||$e, qr/Close with partial character/,
     'no crash when assigning glob to buffer in encode';
$buf = "To hymn him who heard her herd herd\n";
open $fh, "<:encoding(globber)", \$buf;
my $x = <$fh>;
close $fh;
is $x, "To hymn him who heard her herd herd\n",
     'no crash when assigning glob to buffer in decode';

END {
    1 while unlink($grk, $utf, $fail1, $fail2, $russki, $threebyte);
}
