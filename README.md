# dweet_client
Questo è un programma C/C++ che mostra come utilizzare **[dweet.io](https://dweet.io/)** per lo storage di informazioni nel cloud.
Il programma è scritto sia in C che in C++, per attivare uno o l'altro basta aggiungerli/rimuoverli dal progetto Codeblocks (se aggiunge quello che interessa e si rimuove quello che non interessa). L'eseguibile che si ottiene compilando le due versioni è funzionalmente identico.

Il programma va usato da linea di comando, passandogli i parametri che interessano nel modo seguente:
```
dweet_client usage: dweet_client OPTIONS
OPTIONS:
-i: interactive mode
-p: post a value to dweet.io
        Example:
         dweet_client -p thing_name name value
-g: get values from dweet.io and output them
        Example:
         dweet_client -g thing_name
```
Come si vede si sono tre possibilità:
* **-i** interattiva: pone delle domande a linea di comando, basta rispondere per inviare/recuperare un dato a/da dweet.io (questa modalità è anche quella che viene eseguita se si esegue il programma all'interno di Codeblocks).
* **-g** get: recupera i dati di una cosa da dweet, bisogna anche accodare il nome della cosa
* **-p** post: invia i dati di una cosa a dweet, bisogna anche accodare il nome della cosa, la chiave e il valore da inviare

In realtà il programma usa **[curl](https://curl.haxx.se/)** per la comunicazione su rete, quindi si limita a costruire la stringa che contiene la chiamata corretta a *curl* per effettuare l'operazione desiderata. Ne consegue che l'eseguibile *curl* deve trovarsi o nella cartella di progetto di Codeblocks, se il programma viene eseguito all'interno dell'IDE, o nella cartella dove si trova l'eseguibile generato per compilazione di questo progetto. 
*curl* è un programma libero che può essere facilmente recuperato in rete (nella distribuzioni Linux solitamente è già installato).
