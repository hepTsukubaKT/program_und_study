#include <stdio.h>

int GmCalc_n(void)
{
  c1 = new TCanvas("c1" , "c1 title" , 200 , 100, 800, 600);

  string CHIP;
  cout << "CHIP : " << flush;
  cin >> CHIP;

  string FET;
  cout << "FET  : " << flush;
  cin >> FET;

  string Vds;
  cout << "Vds  : " << flush;
  cin >> Vds;

  TCanvas* c=new TCanvas("c","gm-temp plot", 800, 700);
  c->Draw();
  c->SetBorderMode(0);
  c->SetGridx();
  c->SetGridy();
  c->SetFillColor(0);
  
  gStyle->SetTitleFillColor(0);
  gStyle->SetTitleBorderSize(1);
  
  c->SetFrameBorderMode(0);

  TLegend *leg = new TLegend(0.13, 0.70 , 0.27, 0.88,"Temperature","NDC");
  leg->SetTextSize(0.03);
  leg->SetBorderSize(0);
  leg->SetFillStyle(0);
  leg->SetFillColor(0);

  float VG[N][NUM_DATA] = {0.};
  float ID[N][NUM_DATA] = {0.};
  float Gm[N][NUM_DATA] = {0.};

  


  return 0;
}
