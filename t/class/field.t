#!./perl

BEGIN {
    chdir 't' if -d 't';
    require './test.pl';
    set_up_inc('../lib');
    require Config;
}

use v5.36;
use feature 'class';
no warnings 'experimental::class';

# We can't test fields in isolation without having at least one method to
# use them from. We'll try to keep most of the heavy testing of method
# abilities to t/class/method.t

# field in method
{
    class Test1 {
        field $f;
        method incr { return ++$f; }
    }

    my $obj = Test1->new;
    $obj->incr;
    is($obj->incr, 2, 'Field $f incremented twice');

    my $obj2 = Test1->new;
    is($obj2->incr, 1, 'Fields are distinct between instances');
}

# fields are distinct
{
    class Test2 {
        field $x;
        field $y;

        method setpos { $x = $_[0]; $y = $_[1] }
        method x      { return $x; }
        method y      { return $y; }
    }

    my $obj = Test2->new;
    $obj->setpos(10, 20);
    is($obj->x, 10, '$pos->x');
    is($obj->y, 20, '$pos->y');
}

# fields of all variable types
{
    class Test3 {
        field $s;
        field @a;
        field %h;

        method setup {
            $s = "scalar";
            @a = ( "array" );
            %h = ( key => "hash" );
            return $self; # test chaining
        }
        method test {
            ::is($s,      "scalar", 'scalar storage');
            ::is($a[0],   "array",  'array storage');
            ::is($h{key}, "hash",   'hash storage');
        }
    }

    Test3->new->setup->test;
}

# fields can be captured by anon subs
{
    class Test4 {
        field $count;

        method make_incrsub {
            return sub { $count++ };
        }

        method count { return $count }
    }

    my $obj = Test4->new;
    my $incr = $obj->make_incrsub;

    $incr->();
    $incr->();
    $incr->();

    is($obj->count, 3, '$obj->count after invoking closure x 3');
}

# fields can be captured by anon methods
{
    class Test5 {
        field $count;

        method make_incrmeth {
            return method { $count++ };
        }

        method count { return $count }
    }

    my $obj = Test5->new;
    my $incr = $obj->make_incrmeth;

    $obj->$incr;
    $obj->$incr;
    $obj->$incr;

    is($obj->count, 3, '$obj->count after invoking method-closure x 3');
}

# fields of multiple unit classes are distinct
{
    class Test6::A;
    field $x; ADJUST { $x = "A" }
    method m { return "unit-$x" }

    class Test6::B;
    field $x; ADJUST { $x = "B" }
    method m { return "unit-$x" }

    package main;
    ok(eq_array([Test6::A->new->m, Test6::B->new->m], ["unit-A", "unit-B"]),
        'Fields of multiple unit classes remain distinct');
}

# fields can be initialised with constant expressions
{
    class Test7 {
        field $scalar = 123;
        method scalar { return $scalar; }

        field @array = (4, 5, 6);
        method array { return @array; }

        field %hash  = (7 => 89);
        method hash { return %hash; }
    }

    my $obj = Test7->new;

    is($obj->scalar, 123, 'Scalar field can be constant initialised');

    ok(eq_array([$obj->array], [4, 5, 6]), 'Array field can be constant initialised');

    ok(eq_hash({$obj->hash}, {7 => 89}), 'Hash field can be constant initialised');
}

# field initialiser expressions are evaluated within the constructor of each
# instance
{
    my $next_x = 1;
    my @items;
    my %mappings;

    class Test8 {
        field $x = $next_x++;
        method x { return $x; }

        field @y = ("more", @items);
        method y { return @y; }

        field %z = (first => "value", %mappings);
        method z { return %z; }
    }

    is($next_x, 1, '$next_x before any objects');

    @items = ("values");
    $mappings{second} = "here";

    my $obj1 = Test8->new;
    my $obj2 = Test8->new;

    is($obj1->x, 1, 'Object 1 has x == 1');
    is($obj2->x, 2, 'Object 2 has x == 2');

    is($next_x, 3, '$next_x after constructing two');

    ok(eq_array([$obj1->y], ["more", "values"]),
        'Object 1 has correct array field');
    ok(eq_hash({$obj1->z}, {first => "value", second => "here"}),
        'Object 1 has correct hash field');
}

# fields are visible during initialiser expressions of later fields
{
    class Test9 {
        field $one   = 1;
        field $two   = $one + 1;
        field $three = $two + 1;

        field @four = $one;
        field @five = (@four, $two, $three);
        field @six  = grep { $_ > 1 } @five;

        method three { return $three; }

        method six { return @six; }
    }

    my $obj = Test9->new;
    is($obj->three, 3, 'Scalar fields initialised from earlier fields');
    ok(eq_array([$obj->six], [2, 3]), 'Array fields initialised from earlier fields');
}

done_testing;
