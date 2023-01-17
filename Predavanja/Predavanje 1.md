# Predavanje 1

## Uvod

- U ovom uvodnom poglavlju se predstavljaju osnovna svojstva algoritama, načini njihovog stvaranja i zapisivanja

### O algoritmima

- Drugi dio poglavlja se bavi općenitim opisom struktura podataka, tipičnim operacijama nad njima i klasifikacijama po različitim kriterijima

- Na kraju se algoritmi i strukture podataka razmatraju u kontekstu razvoja softvera i naglašava se njihov značaj za implementaciju različitih sistema

- Pojam algoritma dolazi od imena perzijskog matematičara Muhameda ibn Musa al Horezmija

- U knjizi "Račun sa Hindu brojkama" al Horezmi je opisao indijsku notaciju i pravila za obavljanje aritmetičkih operacija nad brojevima u dekadskom sistemu

- Knjiga je prevedena na latinski pod naslovom "Algoritmi de numero indorum"

- Riječ algoritam se prvobitno koristila samo za pravila računanja sa indijskim brojevima, a danas se podrazumijevaju pravila za obavljanje zadataka u različitim oblastima, najčešće u računarstvu

- Algoritam se definira kao precizno definirana procedura u obliku uređenog skupa jednoznačnih izvedivih koraka, sa definiranim redoslijedom izvođenja

- Algoritmi imaju jedan ili više precizno definiranih ulaznih početnih objekata, izlazni objekat/rezultat, sastavljeni su od konačnog broja koraka, završavaju se u konačnom vremenu i naredbe su jasne i nedvosmislene

- Koraci algoritma se mogu izvoditi sekvencijalno ili paralelno. Paralelni algoritmi sadrže niti koje se izvode na više procesora

- Algoritamski proces se sastoji od gradnje izlaznih objekata, uz pojavu međurezultata

- Algoritmi su deterministički, što znači da pod istim uvjetima imaju predvidljivo i očekivano ponašanje.

#### Zapisivanje i stvaranje algoritama

- Algoritmi se mogu opisati prirodnim govornim jezikom, grafički u obliku dijagrama toka ili u umjetnom jeziku-programskom jeziku

- Zapisivanje algoritma u programskom jeziku zahtijeva poznavanje pravila tog jezika, ali zapis u pseudojeziku omogućuje bolju razumljivost osnovnih zamisli

- Algoritmi nastaju na različite načine: iz znanstvenih teorija, praktičnog iskustva i prethodno već kreiranih algoritama

- Teorijski algoritmi nastaju iz matematičkih teorema

- Eksperimentalni algoritmi nastaju iz opažanja i eksperimentiranja

- Algoritmi koji se temelje na prethodno već kreiranim algoritmima se nazivaju evolucijskim algoritmima

#### Konvencije pseudojezika

- Konvencije pseudojezika se koriste kako bi se algoritmi lakše razumjeli, jer uklanjaju implementacijske detalje

- Pseudojezik sadrži kontrolne strukture (while, repeat, for) i označava kraj struktura sa end + ime strukture
  Pseudojezik sadrži strukturu izbora (if) i označava kraj sa end_if

- Pseudojezik sadrži uobičajenu dodjelu vrijednosti označenu sa = i dozvoljava višestruku dodjelu vrijednosti

- Pseudojezik sadrži simbol == za testiranje ekvivalentnosti i simbol  za razmjenu vrijednosti

- Pseudojezik omogućuje pristup elementima niza putem indeksa u uglatim zagradama i označava raspon elemenata niza sa ".."

- Pseudojezik organizira složene podatke u objekte sa atributima i omogućuje pristup atributima preko navođenja imena objekta i atributa.

#### Napomene o primjerima u jeziku C++

- U knjizi se koristi pseudojezik za prikaz algoritama, a za većinu algoritama daju se i primjeri njihove realizacije u programskom jeziku C++. Potrebno je poznavati C++ da bi se razumjele te implementacije jer se ne opisuju detalji vezani za jezik, te se u njima primjenjuje objektno orijentirani pristup. Uz primjere su navedeni i testni programi za ilustraciju rada.

### O strukturama podataka

- Strukture podataka su organizirani skupovi podataka koji se koriste u programskim jezicima kako bi se olakšala obrada i manipulacija podacima.

- Postoje dva osnovna tipa struktura podataka: nizovi (homogene strukture koje sadrže elemente istog tipa) i zapisi (nehomogene strukture koje sadrže elemente različitog tipa).

- Strukture podataka se mogu kombinirati kako bi se stvorile strukture proizvoljne složenosti, te se koriste za povećanje nivoa apstrakcije prikaza i obrade podataka.

#### Klasifikacija strukturnih podataka

- Klasifikacija struktura podataka je važan korak u razvoju programskih sistema, jer određuje način na koji se podaci čuvaju i obrađuju.

- Jedan od mogućih kriterija za klasifikaciju struktura podataka je međusobne relacije elemenata u strukturi, na primjer linearne strukture (niz, povezana lista, stek, red) i nelinearne strukture (stablo, graf).

- Drugi kriterij je mogućnost promjene veličine strukture podataka tokom izvršavanja programa, koji dijeli strukture na statičke i dinamičke.

- Strukture podataka koje se pohranjuju na vanjskim memorijama se nazivaju datoteke, koje se klasificiraju prema načinu organizacije podataka i skupu operacija kojima se pristupa pojedinim zapisima.

#### Memorijski prikaz struktura podataka

- Memorijski prikaz struktura podataka se odnosi na način na koji se struktura podataka pohranjuje u memoriji računala.

- Postoje dva glavna načina memorijskog prikaza: sekvencijalni (kontinualni) i ulančani (nekontinualni) prikaz.

- Sekvencijalni prikaz podrazumijeva da su elementi strukture raspoređeni u kontinualnom memorijskom prostoru, dok su elementi ulančanog prikaza raspoređeni na proizvoljnim mjestima u memoriji.

- Ulančani prikaz se koristi za implementaciju nelinearnih struktura, dok se sekvencijalni prikaz koristi za implementaciju linearnih struktura.

- Međutim, ulančani prikaz može donijeti bolje performanse za obavljanje određenih operacija, dok je pristup elementima u ulančanom prikazu sporiji zbog potrebe za slijeđenjem niza pokazivača.

#### Operacije sa strukturama podataka

- Operacije sa strukturama podataka su radnje koje se izvode na elementima strukture podataka, kao što su pristup elementima radi čitanja ili dodjele nove vrijednosti, obilazak svih elemenata, pretraživanje, umetanje novog elementa, brisanje elementa strukture, itd.

- Operacije su različite za različite strukture podataka i uključuju logičku i fizičku implementaciju strukture podataka. Primjerice, operacija obilaska je jednostavnija za linearne strukture, dok je za nelinearne strukture složenija i zahtijeva različite algoritme.

- Pretraživanje elementa se također može izvesti efikasnije za uređene strukture podataka, dok umetanje novog elementa može biti neefikasnije za uređene strukture podataka u odnosu na neuređene strukture podataka.

### Algoritmi i strukture podataka u kontekstu razvoja softvera

#### Apstraktni pogled na problem i kreiranje modela

- Da bi se riješio problem u softverskom razvoju, potrebno je identificirati bitna svojstva problema, kao što su relevantni podaci i operacije za manipulaciju tih podataka.

- Proces stvaranja apstraktnog pogleda na problem, koji se naziva apstrakcija, uključuje strukturiranje nejasnih problema u dobro definirane entitete, koji se nazivaju apstraktni tipovi podataka.

- Apstraktni tipovi podataka su strukture podataka koje se mogu pristupiti preko definiranih operacija. Oni se mogu implementirati na različite načine, ovisno o konkretnom programskom jeziku.

#### Značaj algoritama i struktura podataka

- Algoritmi i strukture podataka su ključni elementi za implementaciju programskih rješenja. Poznavanje temeljnih i često korištenih algoritama i struktura podataka je neophodno za pisanje kvalitetnog programskog koda. Oni su važni za dizajniranje i razvoj složenijih softverskih proizvoda, koji će svoju upotrebu naći u stvarnom svijetu.

- Softverski inženjering je oblast koja se bavi dizajnom, razvojem, proizvodnjom i održavanjem računarskih programa, u kojoj se koriste različiti algoritmi i strukture podataka. Upotreba metodologija, standarda kodiranja i testiranja, omogućuju razvoj softvera koji zadovoljava određene standarde kvalitete.
