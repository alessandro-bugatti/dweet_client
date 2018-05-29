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
 *  \date  Creazione  26/05/2017
 *  \date  Ultima modifica 26/05/2017
 *
 */

#include <iostream>
#include <string>
#include <cstdlib>

using namespace std;

int main(int argc, char *argv[])
{
    string thing;
    string action;
    string command;
    string name;
    string value;
    string file;
    /**
    *   Ci sono tre modalità: interattiva, per spedire un dato (post)
    *   o per ricevere un dato (get)
    */
    //Modalità interattiva
    if ((argc == 2 && string(argv[1]) == "-i")   || argc == 1)
    {
        cout << "Interactive mode" << endl;
        cout << "Thing name: ";
        getline(cin, thing);
        cout << "Action [p]ost/[g]et: ";
        getline(cin,action);
        if (action.at(0) == 'p')
        {
            cout << "Parameter name: ";
            getline(cin,name);
            cout << "Parameter value: ";
            getline(cin,value);
            command = "curl https://dweet.io/dweet/for/";
            command += thing + "?" + name + "=" + value;
        }
        else if (action.at(0) == 'g')
        {
            cout << "Output file (default stdout): ";
            getline(cin,file);
            command = "curl https://dweet.io/get/latest/dweet/for/";
            command += thing;
            if (file.size() > 1)
                command += " > " + file;
        }
        else
        {
            cout << "Not a valid option [p/g]\n";
            return 1;
        }
    }
    //Modalità get
    else if (argc == 3 && string(argv[1]) == "-g")
        command = string("curl https://dweet.io/get/latest/dweet/for/") + argv[2];
    //Modalità post
    else if (argc == 5 && string(argv[1]) == "-p")
        command = string("curl https://dweet.io/dweet/for/") +
        argv[2] + "?" + argv[3] + "=" + argv[4];
    else
    {
        cout << "dweet_client usage: dweet_client OPTIONS " << endl
        << "OPTIONS:" << endl
        << "-i: interactive mode" << endl
        << "-p: post a value to dweet.io" << endl
        << "\tExample:" << endl
        << "\t dweet_client -p thing_name name value" << endl
        << "-g: get values from dweet.io and output them" << endl
        << "\tExample:" << endl
        << "\t dweet_client -g thing_name" << endl;
        return 1;
    }
    cout << command << endl;
    system(command.c_str());
    return 0;
}
