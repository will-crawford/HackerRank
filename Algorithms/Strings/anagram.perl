use feature qw/ say /;
use List::Util qw/ sum /;

for ( 1 .. <> ) {
    my $s = <>; chomp $s;
    warn $s;
    my $l = length $s;
    if ( $l & 1 ) { say -1; next; }
    my $middle = int( ( $l + 1 ) / 2 );
    my $a = substr( $s, 0, $middle ), $b = substr( $s, $middle );
    my ( %counts ) = ( );
    ++$counts{$_} for split '', $a;
    --$counts{$_} for split '', $b;
    my $changes = 0 + sum grep { $_ > 0 } values %counts;
    say $changes;
}
