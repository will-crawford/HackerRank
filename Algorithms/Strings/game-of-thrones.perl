use feature qw/ say /;
my $s = <>; chomp $s;
my (@counts);
my $l = length $s;
for ( my $i = 0; $i < $l; ++$i ) { ++$counts[ ord( substr($s, $i, 1) ) - ord( 'a' ) ]; }
my $odds = 0;
for my $c (@counts) {
    if ( $c % 2 && $odds++ ) { say "NO"; exit 0; }
}
say "YES";
