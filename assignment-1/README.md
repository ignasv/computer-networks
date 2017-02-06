## Užduoties aprašymas
Pirmosios užduoties esmė - tarpprograminis bendravimas per TCP/IP socket'us. Programą turi sudaryti dvi dalys - klientas ir serveris. Dalykinė sritis pasirenkama laisvai - tai gali 
būti įvairūs žaidimai, "nutolę" (remote) skaičiavimai, piešimai, duomenų bazės ir pan. Programoms pakanka turėti tekstinį interfeisą. Uždavinį kiekvienas studentas susigalvoja pats, 
arba pasirenka iš žemiau pateiktų pavyzdžių, tačiau uždaviniai neturi kartotis pogrupyje. Apie pasirinktą užduotį būtina pranešti man.

Aprašymas [angliškai](README.en.md)

## Reikalavimai
* Programa turi būti įgyvendinta C/C++ programavimo kalba.
* Programa turi turėti bent minimalius parametrus - kokiu portu kurti socket'ą ar prie jo jungtis, prie kokio host'o jungtis. 
* Serveris neturi baigti darbo aptarnavęs tik vieną klientą. 
* Klientas neturi baigti darbo atlikęs vieną užklausą (reikalavimas nebūtinas, jei yra neprasmingas konkretaus uždavinio atveju).
* Serveris turi gebėti aptarnauti kelis klientus vienu metu.
* Programos rašomos naudojant BSD sockets arba analogiškus Winsock interfeisus. Nenaudojami aukštesnio abstrakcijos lygio interfeisai. 
* Programų išeities tekstai turi būti tvarkingi, laikantis jei ne objektinio, tai bent struktūrinio programavimo, su prasmingais metodų, kintamųjų ir kt. pavadinimais, komentarais.

## Dalykinės srities pavyzdžiai
* Reisų(autobusų, lėktuvų, etc.) tvarkaraštis, vietų rezervacija.
* Videonuoma, knygynas, e-parduotuvė, picų, tortų ir pan. užsisakymas.
* Įvairios DB - žmonių, knygų, filmų - su registracija bei paieška.
* Nutolęs kalkuliatorius.
* Fibonačio skaičiai.
* Užrašų knygutė.
* Žinučių (pašto) serveris.
* Failų serveris.
* Banko veikla, bankomatas (sąskaitos, operacijos).
* Žodynas serveryje (vertimai).
* Testai/viktorinos/apklausos/matematiniai uždavinukai (klausimai/atsakymai).
* Žodžio spėjimas, kartuvės.
* Lines.
* Black jack.
* Laivų mūšis.
* Skaičių spėjimai (su pasakymu daugiau mažiau; su pasakymu, kiek skaitmenų atspėta ir kiek savo vietoj)
* Šaškės, šachmatai.
* Reversi.
* Kryžiukai nuliukai.
* Degtukų žaidimas (kas paims paskutinį).
* Žaidimas Taip/ne.
* Gyvatė tinkle.
* Kiti žaidimai, nutolę piešimai, skaičiavimai ir t.t.

## Nuorodos
http://beej.us/guide/bgipc/output/html/multipage/unixsock.html

http://www.linuxhowtos.org/C_C++/socket.htm