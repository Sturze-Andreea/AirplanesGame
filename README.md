# AirplanesGame
Avioane
Fiecare jucător are propria lui tablă pe care amplaseză k avioane. Fiecare piesă este formată
din mai multe pătrățele sub forma unui avion (mai multe pătrățele identice si un părtățel
special numit panou de comandă al piesei curente).
Exemplu de tablă cu k = 3 avioane.

La o mutare, un jucător trebuie să ghicească poziția pieselor celuilalt jucător, comunicând
poziția acestei căsuțe; drept răspuns celălalt jucător poate răspunde:
- aer - dacă acea poziție nu conținea nici o piesă
- lovit - dacă pe acea pozție se află o parte dintr-o piesă
- distrus - dacă pe acea poziție se află panoul de comandă al unei piese
Scopul unui jucător este de a identifica poziția tuturor vaselor de pe tabla adversarului, deci
jocul se termină când toate piesele unui jucător au fost identificate complet. Jocul este câștigat
de jucătorul care a efectuat ultima mutare (care a identificat complet toate piesele
adversarului). 

- se joacă de către 2 jucători (un utilizator și un calculator)
- se joacă pe o tablă matriceală de dimensiune n x m, cu liniile numerotate cu litere, iar
coloanele cu numere (n, m - numere naturale mai mici decât 32)
- fiecare jucător amplasează piesele pe tabla lui de joc; piesele se amplasează astfel încât să
se încadreze pe tabla de joc și să nu se suprapună; pisele jucătorului uman se amplasează
conform dorințelor acestuia (citite de la tastatură sau preluate dintr-un fișier); pieslee
jucătorului computer se amplasează la întâmplare la pornirea jocului.
- jucătorii efectueză, pe rând și alternativ, câte o mutare
- jocul se termină când toate piesele unui jucător au fost distruse sau identificate
- jocul este câștigat de jucătorul care a efectuat ultima mutare (care a distrus sau identificat
complet toate piesele adversarului) 
