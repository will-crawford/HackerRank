
use feature qw/ say /;
use POSIX;

srand (time);
sub random ($) { return int floor ( rand() * shift ); }

say 5;
my $n = 3 + random( 194 );
for ( my $t = 0; $t < 5; ++$t, ++$n ) {
    my $cancel = 0 + !( $t & 1 );
    my $k = $n - random( $n - 2 );
    say "$n $k";
    my $a0 = $k - $n - $cancel;
    say join( ' ', ( $a0 .. ( $a0 + $n - 1 ) ) );
}
