# Descrierea task-ului
Această temă presupune crearea unui joc asemănător cu TypeRacer utilizând Arduino Uno.

## Joc
Se alege dificultatea jocului folosind butonul de dificultate, iar în terminal va apărea “Easy/Medium/Hard mode on!”.

Se apasă butonul de start/stop.

LED-ul clipește timp de 3 secunde, iar în terminal se va afișa numărătoarea înversă: 3, 2, 1.

LED-ul devine verde și încep să apară cuvinte de tastat.

La tastarea corectă, următorul cuvânt apare imediat. Dacă nu se tasteaza cuvântul în timpul stabilit de dificultate, va apărea un nou cuvânt.

O greșeală face LED-ul să devină roșu. Pentru a corecta cuvântul, se va folosi tasta Backspace.

După 30 de secunde, runda se termină, iar în terminal se va afișa scorul: numărul total de cuvinte scrise corect.

Jocul se poate opri oricând cu butonul de start/stop.

## Componente utilizate

- Arduino UNO (ATmega328P microcontroller)
- 1x LED RGB (pentru a semnaliza dacă cuvântul corect e scris greșit sau nu)
- 2x Butoane (pentru start/stop rundă și pentru selectarea dificultății)
- 5x Rezistoare (3x 220/330 ohm, 2x 1000 ohm)
- Breadbord
- Fire de legătură

## Montaj fizic
![Poza 1](poze/poza1.jpg)
![Poza 2](poze/poza2.jpg)
![Poza 3](poze/poza3.jpg)

## Schema electrică
![Schema electrică](poze/schema_electrica.png)

Video cu funcționalitatea montajului: TBD