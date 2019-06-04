/*
  Copyright (C) 2017 Alessandro Bugatti (alessandro.bugatti@istruzione.it)

  This program is free software; you can redistribute it and/or
  modify it under the terms of the GNU General Public License
  as published by the Free Software Foundation; either version 2
  of the License, or (at your option) any later version.

  This program is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
  GNU General Public License for more details.

  You should have received a copy of the GNU General Public License
  along with this program; if not, write to the Free Software
  Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301, USA.
*/

/*! \file
 *  \brief Esempio di utilizzo di dweet.io per memorizzare dati nel cloud
 *  Viene utilizzato curl per fare il lavoro vero, quindi bisogna assicurarsi
 *  che sia installato oppure che si trovi fianco a fianco con l'eseguibile
 *  \author Alessandro Bugatti
 *
 *  \version 0.1
 *  \date  Creazione  26/05/2019
 *  \date  Ultima modifica 26/05/2019
 *
 */

#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>

using namespace std;

int main(int argc, char *argv[])
{
    string thing;
    const string filename = "dweet.conf";
    string command;
    string key, value;
    //Modalità post
    //Si leggono i dati da un file (dweet.conf) in cui la prima riga
    //indica la "cosa", la seconda la chiave e la terza il valore
    ifstream in;
    in.open("dweet.conf");
    if (in.fail())
    {
        cout << "File di configurazione non trovato" << endl;
        return 1;
    }
    in >> thing >> key >> value;
    command = "curl https://dweet.io/dweet/for/" +
        thing + "?" + key + "=" + value;
    cout << command << endl;
    system(command.c_str());
    return 0;
}
