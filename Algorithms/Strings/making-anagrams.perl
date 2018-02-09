use feature qw/ say /;

my $a = <>; my $b = <>; chomp $a; chomp $b;
my (@ac, @bc);
for ( my ( $i, $n ) = ( 0, length $a ); $i < $n; ++$i ) {
    ++$ac[ ord( substr( $a, $i, 1 ) ) - ord('a') ];
}
for ( my ( $i, $n ) = ( 0, length $b ); $i < $n; ++$i ) {
    ++$bc[ ord( substr( $b, $i, 1 ) ) - ord('a') ];
}

my $d = 0;
for ( my $i = 0; $i < 26; ++$i ) {
    $d += abs( $bc[$i] - $ac[$i] );
}
say $d;
