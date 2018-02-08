#!/usr/bin/perl

use feature qw/ say /;

my $line, @gmail;

for ( 1 .. <> ) {
    chomp( $line = <> );
    my ($name, $email) = split ' ', $line;
    push ( @gmail, $name ) if $email =~ /\@gmail\.com$/;
}
    
say join "\n", sort @gmail;
