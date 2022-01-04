
#include <cs50.h>
#include <stdio.h>

int sjekk_lengde(long kredittkort);
int sjekk_sum(long kredittkort);
int sjekk_kredittkort(long kredittkort);

int main(void)
{
    // Spør brukeren om kredittkortnummber
    long kredittkort = get_long("Kredittkortnummer: ");

    // Sjekk om kredittkort har korrekt lengde og om kredittkortet er gyldig
    if (sjekk_lengde(kredittkort) == 0 || sjekk_sum(kredittkort) == 0 || sjekk_kredittkort(kredittkort) == 0)
    {
        printf("INVALID\n");
    }

    
}

int sjekk_lengde(long kredittkort)
{
    long kortlengde = 0;
    long kkort = kredittkort;
    while (kkort > 0)
    {
        kkort = kkort / 10;
        kortlengde++;
    }

    // Sjekk om lengden er gyldig
    if (kortlengde != 13 && kortlengde != 15 && kortlengde != 16)
    {
        // printf("INVALID\n");
        return 0;
    }
    return 1;
}

int sjekk_sum(long kredittkort)
{
    // Kalkuler sjekksum
    int sum1 = 0;
    int sum2 = 0;
    int totalt = 0;
    int modulusfirst, modulussecond;
    int d1;
    int d2;

    // Looper over kredittkortlengden
    do
    {
        // Henter siste tall fra kredittkortet
        modulusfirst = kredittkort % 10;
        // Fjerner siste tall fra kredittkortet
        kredittkort = kredittkort / 10;
        // Legg til i sum1 (Tallene som ikke skal ganges med to)
        sum1 = sum1 + modulusfirst;

        // Registrer nest siste tall i kredittkortet.
        modulussecond = kredittkort % 10;
        // Fjern nest siste tall fra kredittkortet.
        kredittkort = kredittkort / 10;

        // Gang annenhvert tall med 2 (modulussecond henter hvert 2. tall)
        modulussecond = modulussecond * 2;
        // Eksempelkredittkort = 1•2 + 0•2 + 0•2 + 0•2 + 0•2 + 6•2 + 0•2 + 4•2

        d1 = modulussecond % 10;
        d2 = modulussecond / 10;
        sum2 = sum2 + d1 + d2;
    } while (kredittkort > 0);
    totalt = sum1 + sum2;
    if (totalt % 10 != 0)
    {
        return 0;
    }
    return totalt;
}

// Sjekk startnumre, finn de to første tallene.
int sjekk_kredittkort(long kredittkort)
{
    do
    {
        kredittkort = kredittkort / 10;
    } while (kredittkort > 100);

    // Sjekk kredittkortnumre Mastercard 51, 52, 53, 54 eller 55
    if ((kredittkort / 10 == 5) && (0 < kredittkort % 10 && kredittkort % 10 < 6))
    {
        printf("MASTERCARD\n");
        return 1;
    }
    // Sjekk kredittkortnumre American Express 34 eller 37
    else if ((kredittkort / 10 == 3) && (kredittkort % 10 == 4 || kredittkort % 10 == 7))
    {
        printf("AMEX\n");
        return 1;
    }
    // Sjekk kredittkortnumre Visa 4
    else if (kredittkort / 10 == 4)
    {
        printf("VISA\n");
        return 1;
    }
    return 0;
}
