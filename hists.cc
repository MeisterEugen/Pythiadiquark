#include "TFile"
#include "TH1.h"
#include <stdio.h>

int main () {

TH1D *soft, *hard, *wdi, *odi;

TFile *input1 = new TFile ("pp_baryons/pp_pip_soft_1234.root", "READ");

soft = (TH1D*) input1->Get("h_proton_pt");
  soft->SetName("Soft");

TFile *input2 = new TFile("pp_baryons/pp_pip_hard_1234.root", "READ");

hard = (TH1D*)input2->Get("h_proton_pt");
hard->SetName("hard");
TFile *input3 = new TFile("pp_baryons/pp_pip_wdi_1234.root", "READ");

wdi = (TH1D*)input3->Get("h_proton_pt");
wdi->SetName("wdi");
TFile *input4 = new TFile("pp_baryons/pp_pip_odi_1234.root");

odi = (TH1D*)input4->Get("h_proton_pt");
odi->SetName("odi");
TFile *output = new TFile ("hists.root", "RECREATE");
soft->Write();
hard->Write();
wdi->Write();
odi->Write();

output->Write();
return 0;
}
