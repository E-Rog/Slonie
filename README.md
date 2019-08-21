# Slonie
W Bajtockim Zoo ma się za chwilę odbyć parada, w której uczestniczyć będą wszystkie
znajdujące się w nim słonie. Pracownicy zoo zachęcili już zwierzęta do ustawienia się w jednym
rzędzie, gdyż zgodnie z zarządzeniem dyrektora zoo taka powinna być początkowa figura parady.
Niestety, na miejsce przybył sam dyrektor i zupełnie nie spodobała mu się wybrana
przez pracowników kolejnosć słoni. Dyrektor zaproponował kolejnosć, w której według niego
zwierzęta będą się najlepiej prezentować, i wydał pracownikom polecenie poprzestawiania słoni
zgodnie z tą propozycją.
Aby uniknąć nadmiernego chaosu tuż przed paradą, pracownicy postanowili przestawiać
słonie, zamieniając miejscami kolejno pewne pary słoni. Przestawiane zwierzęta nie muszą
sąsiadować ze sobą w rzędzie. Wysiłek potrzebny do nakłonienia słonia do ruszenia się z miejsca
jest wprost proporcjonalny do jego masy, a zatem wysiłek związany z zamianą miejscami
dwóch słoni o masach m1 oraz m2 można oszacować przez m1+m2. Jakim minimalnym wysiłkiem
pracownicy mogą poprzestawiać słonie tak, aby usatysfakcjonować dyrektora?
Napisz program, który:
• wczyta ze standardowego wejscia masy wszystkich słoni z zoo oraz aktualną i docelową
kolejnosć słoni w rzędzie,
• wyznaczy taki sposób poprzestawiania słoni, który prowadzi od kolejnosci początkowej
do docelowej i minimalizuje sumę wysiłków związanych ze wszystkimi wykonanymi
zamianami pozycji słoni,
• wypisze sumę wartosci tych wysiłków na standardowe wyjscie.
Wejscie
Pierwszy wiersz wejscia zawiera jedną liczbę całkowitą n (2 6 n 6 1 000 000 ), oznaczającą
liczbę słoni w Bajtockim Zoo. Dla uproszczenia zakładamy, że słonie są ponumerowane od
1 do n. Drugi wiersz zawiera n liczb całkowitych mi (100 6 mi 6 6 500 dla 1 6 i 6 n),
pooddzielanych pojedynczymi odstępami i oznaczających masy poszczególnych słoni (wyrażone
w kilogramach).
Trzeci wiersz wejscia zawiera n różnych liczb całkowitych ai (1 6 ai 6 n), pooddzielanych
pojedynczymi odstępami i oznaczających numery kolejnych słoni w aktualnym ustawieniu.
Czwarty wiersz zawiera n różnych liczb całkowitych bi (1 6 bi 6 n), pooddzielanych pojedynczymi
odstępami i oznaczających numery kolejnych słoni w ustawieniu proponowanym przez
dyrektora zoo. Możesz założyć, że ustawienia reprezentowane przez ciągi ( ai) oraz ( bi) są
różne.
72 Słonie
Wyjscie
Pierwszy i jedyny wiersz wyjscia powinien zawierać jedną liczbę całkowitą, oznaczającą
minimalny łączny wysiłek związany z poprzestawianiem słoni, w wyniku którego z ustawienia
reprezentowanego przez ( ai) uzyskuje się ustawienie ( bi).
Przykład
Dla danych wejsciowych:
6
2400 2000 1200 2400 1600 4000
1 4 5 3 6 2
5 3 2 4 6 1
poprawnym wynikiem jest:
11200
Jeden z najlepszych sposobów poprzestawiania słoni uzyskujemy, zamieniając miejscami
kolejno pary słoni:
• 2 i 5 — wysiłek związany z zamianą to 2 000+1 600 = 3 600 , a uzyskane ustawienie to
1 4 2 3 6 5,
• 3 i 4 — wysiłek to 1 200+2 400 = 3 600 , a uzyskane ustawienie to 1 3 2 4 6 5,
• 1 i 5 — wysiłek to 2 400+1 600 = 4 000 , a uzyskane ustawienie to 5 3 2 4 6 1, czyli
ustawienie docelowe.
