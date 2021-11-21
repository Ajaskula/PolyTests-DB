# Baza danych testów wielomianów

## Ważne informacje

1. Plik 'testuj.sh' odwzorowuje najlepiej sposób testowania przez ćwiczeniowców.
2. Plik 'szybciorem.sh' nie uruchamia valgrinda podczas testów, co powoduje że wykonują się one 1000x szybciej. 

## Sposób uruchamiania

1. Umieśić swój program w pliku project.c (jeżeli go nie ma, to należy taki utworzyć i tam wkleić)
2. Dane wejściowe "in" umieścić w folderze '/tests/in' (rozszerzenie .in)
3. Dane wyjściowe "out" umieścić w folderze '/tests/out' (rozszerzenie .out)
5. W folderze głównym uruchomić komendę 'bash testuj.sh'

## Uwagi do działania programu

1. Pliki "in" i odpowiadające im "out" muszą mieć tę samą nazwę
2. Pliku "in" muszą mieć rozszerzenie .in oraz pliki "out" muszą mieć nazwę .out
3. Zwrócić uwagę na komendy podane do kompilacji i weryfikacji dynamicznej pamięci ('gcc' oraz 'valgrind'), gdyż mogą być zmieniane w zależności od projektu
4. Archiwalne testy do zadań będą przechowywane w folderze 'archive'
5. Z powodu wczesnej wersji i braku doświadczenia w bashu, program może zawierać rażące błędy
6. Koniecznie należy używać do uruchamiania komendy 'bash' a nie komendy 'sh'.
7. Testy, których wynikiem są wielomiany wykraczające poza stopień 10 należy umieszczać w folderze 'testy-tablice-dynamiczne' w razie potrzeby przeklejać do folderu tests (czego nie należy uploadować na gita!!!).
8. Poządane nazwy plików z testatmi to te najbardziej głupie i niemożliwe do powtórzenia (w celu zapewnienia unikalności).

## Kontrybucja

1. Można ulepszać program poprzez pull-requesty
2. Należy zwrócić uwagę, aby format testów był zgodny z podaną specyfikacją programu
