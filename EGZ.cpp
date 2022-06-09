#include <iostream>
#include <set>
#include <algorithm>
#include <fstream>
#include <vector>
#include <assert.h>
#include <sstream>
#include <algorithm>
#include <iomanip> 


std::ifstream fd("duom.txt");
std::ofstream fr("atrinkta.txt");
std::ifstream at("atrinkta.txt");
std::ofstream isr("rez.txt");
std::ofstream urlai("url.txt");

void print(const std::string& item)
{
    fr << item << std::endl;
}

void atrinkimas(int &n)
{   
    int eil = 0;
    std::multiset<std::string> zodziai;
    std::string line;
    while (getline(fd, line))
    {   
        eil++;
        std::stringstream ssLine(line);
        std::string name;
        while (ssLine)
        {
            ssLine >> name;
            std::string chars = "=~!@#$%^&*()_+{}:|<>?,./;'\[]1234567890-";
            if (name.find("www.") != std::string::npos || name.find("http") != std::string::npos || name.find(".lt") != std::string::npos || name.find(".com") != std::string::npos || name.find(".site") != std::string::npos) {
                urlai << name << '\n';
            }
            else {
                for (char c : chars) {
                    name.erase(std::remove(name.begin(), name.end(), c), name.end());
                }
                if (!name.empty()) {
                    name[0] = std::tolower(name[0]);
                    name += " ";
                    name += std::to_string(eil);
                    zodziai.insert(name);
                    n++;
                }
            }
        }
    }
    std::for_each(zodziai.begin(), zodziai.end(), &print);
}
void skaiciavimas(int n)
{
    std::vector <std::string> z(n);
    std::vector <std::string> zod;
    std::vector <int> sk(n);
    int zdz = -1;
    int num = 0;
    std::vector <std::string> kur(n);
    isr << std::left << std::setw(40) << " Zodis "<<" | "<< std::left << std::setw(30) << " Pasikartoja kartu "<<" | " << std::left << std::setw(150) << " Siuose puslapiuose " << std::endl;
    isr << "--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------" << '\n';
    for(int i=0;i<n;i++)
    {   
        std::string name;
        at >> name;
        at >> num;
        z[i]=name;
        if (i==0||name!=z[i-1]) {
            zdz++;
            kur[zdz] += (std::to_string(num));
            kur[zdz] += (" ");
            zod.push_back(name);
            sk[zdz]++;
        }
        else if (name == z[i - 1]){
            sk[zdz]++;
            kur[zdz] += (std::to_string(num));
            kur[zdz] += (" ");
        }
    }
    for (int i = 0; i <= zdz; i++) {
        if (sk[i] > 1) {
        isr << std::left << std::setw(40) << zod[i] << " | " << std::left << std::setw(30) << sk[i] << " | " <<std::left<< std::setw(150) << kur[i] << std::endl;
        isr << "--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------" << '\n';
    }
    }
    
}
int main() {
    int n = 0;
    atrinkimas(n);
    skaiciavimas(n);
    return 0;
}