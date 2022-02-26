#include "TFile"
#include "TH1.h"
#include <stdio.h>

int main () {

TH1D *soft, *hard, *wdi, *odi, sh, sw, so;

TFile *input1 = new TFile ("hists.root", "READ");

soft = (TH1D*) input1->Get("soft");


hard = (TH1D*)input1->Get("hard");

sh->Clone(soft);
sh->Divide(hard);
sh->SetName("soft:hard");
wdi = (TH1D*)input1->Get("wdi");
sw->Clone(soft);
sw->Divide(wdi);
sw->SetName("soft:wdi");
odi = (TH1D*)input1->Get("odi");
so->Clone(soft);
so->Divide(odi);
so->SetName("soft:odi");
TFile *output = new TFile ("dividing.root", "RECREATE");
soft->Write();
hard->Write();
wdi->Write();
odi->Write();

output->Write();
return 0;
}
