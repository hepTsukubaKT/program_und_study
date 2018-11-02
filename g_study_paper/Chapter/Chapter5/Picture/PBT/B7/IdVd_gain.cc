//***IdVg_drain.cc*********
// PROGRAM
// TO MULTI-PLOT Ids vs Vds OF SOI-FET 
//               EACH GAIN-VOLTAGE
//

#include <iostream>
#include <fstream>
#include <string>
#include <string.h>

#include "TCanvas.h"
#include "TMultiGraph.h"
#include "TGraph.h"
#include "TStyle.h"
#include "TF1.h"
#include "TH1.h"
#include "TH2.h"
#include "TGraphErrors.h"
#include "TText.h"
#include "TPad.h"
#include "TGaxis.h"
#include "TLegend.h"
#include "TAxis.h"

#include "math.h"

#define N 6; //the number of plots of Vd.
#define NUM_DATA 300;

void IdVd_gain(){

  /*test
  int N;
  std::cout << "The number of plots of Vd = : " << std::flush;
  std::cin >> N;
  */

  std::cout << "------------------------------- " << std::endl;

  std::string CHIP;
  std::cout << "CHIP     : " << std::flush;
  std::cin >> CHIP;

  std::string FET;
  std::cout << "FET      : " << std::flush;
  std::cin >> FET;

  std::string TEMP;
  std::cout << "TEMP     : " << std::flush;
  std::cin >> TEMP;

  float VD[N][NUM_DATA];
  float ID[N][NUM_DATA];

  TCanvas* c=new TCanvas("c","Ids-Vds Plot", 800, 700);
  c->Draw();
  c->SetBorderMode(0);
  // c->SetLogy(1);
  c->SetGridx();
  c->SetGridy();

  c->SetFillColor(0);
  gStyle->SetTitleFillColor(0);
  gStyle->SetTitleBorderSize(1);
  
  c->SetFrameBorderMode(0);

  /*y軸をログにするかどうか(デフォルトはログ)
    扇形にしたいのであればコメントアウトすれば良い*/
  /*c->SetLogy(1);
  c->SetGridx();
  c->SetGridy();*/

  TLegend *leg = new TLegend(0.13, 0.68, 0.28, 0.88,"Vg [V]","NDC");
  leg->SetTextSize(0.03);
  leg->SetBorderSize(0);
  leg->SetFillStyle(0);
  leg->SetFillColor(0);


  TMultiGraph *mg= new TMultiGraph();
  TGraph *g[N];

  float Vg_STEP = -0.4;
  float Vg;
  char  Vg_str[10];

  for(int ii=0; ii<N; ii++){

    // Vd += Vd_STEP
    Vg = 1.8 + Vg_STEP*ii;
    //Vg*=(-1);     // for PMOS

    sprintf(Vg_str,"%.2f",Vg);

    std::string SOISTJ="PTEG2"; //PTEG2の場合
    //std::string SOISTJ="SOISTJ2"; //SOISTJ2の場合
    //std::string SOISTJ="SOISTJ4"; //SOISTJ4の場合
    std::string IV="IdVd";
    std::string _="_";
    std::string SOI_CHIP_FET_IV_=SOISTJ+_+CHIP+_+FET+_+IV+_;

    char FileName[100];
    sprintf(FileName,"%s%.2f_%s_.txt",SOI_CHIP_FET_IV_.c_str(),Vg,TEMP.c_str());
    std::cout << FileName << std::endl;

    std::ifstream ifs(FileName);

    std::string str;

    int iii=0;
    while(getline(ifs,str))
      {

      sscanf(str.c_str(),"%f , %*f, %*f , %*f , %f, %*f, %*f, %*f, %*[ ^,], %*[a-zA-Z0-9: ]",
	     &VD[ii][iii],&ID[ii][iii]); 
      VD[ii][iii] = VD[ii][iii] - 1.8;
	ID[ii][iii]=fabs(ID[ii][iii]); //ID[A]の絶対値を取る
      iii++;

      }// for iii

    g[ii] = new TGraph(iii,VD[ii],ID[ii]);
    g[ii]->SetMarkerStyle(8);
    g[ii]->SetMarkerColor(ii+3);
    g[ii]->SetName(Vg_str);
    
    leg->AddEntry(g[ii],Vg_str,"P");

    mg->Add(g[ii]);

   
  } //for ii

  mg->Draw("AP");

  gROOT->GetColor(3)->SetRGB(0., 0.7, 0.); // Green  (0, 1, 0)->(0, 0.7, 0)
  gROOT->GetColor(5)->SetRGB(1., 0.5, 0.);
  gROOT->GetColor(7)->SetRGB(0., 0.7, 1.);

  //std::string TITLE = "SOISTJ4 "+CHIP+FET+" TEMP:"+TEMP; //SOISTJ4の場合
  std::string TITLE = "PTEG2 "+CHIP+FET+" TEMP:"+TEMP; //SOISTJ3の場合
  //std::string TITLE = "SOISTJ2 "+CHIP+FET+" TEMP:"+TEMP; //SOISTJ2の場合
  mg->SetTitle(TITLE.c_str());
  mg->GetXaxis()->SetTitle("Vds [V]");
  mg->GetYaxis()->SetTitle("Ids [A]"); 
  mg->GetYaxis()->SetTitleOffset(1.2);

  ((TGaxis*)mg->GetYaxis())->SetMaxDigits(2);
   mg->GetXaxis()->SetNoExponent(kTRUE);

  //x軸の設定
  //mg->GetXaxis()->SetLimits(0, 1.0);
  //mg->GetXaxis()->SetLimits(-1.0, 0); /*for PMOS*/

  /*set the value of the Yaxis
  mg->SetMinimum(1e-12);
  mg->SetMaximum(5e-2);*/

  leg->Draw();

  std::cout << "------------------------------ "<<std::endl;

  std::string SEXT=".eps";
  std::string SName=SOI_CHIP_FET_IV_+TEMP+SEXT;
  c->SaveAs(SName.c_str());

  std::string SEXT=".gif";
  std::string SName=SOI_CHIP_FET_IV_+TEMP+SEXT;
  c->SaveAs(SName.c_str());

}
