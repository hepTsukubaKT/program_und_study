//
// PROGRAM
// TO MULTI-PLOT Ids vs Vgs OF SOI-FET 
//               EACH TEMPERATURES
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

#include "math.h"

#define N 2;
#define NUM_DATA 300;

void IdVg_temp(){

  /*
  int N;
  std::cout << "NUMBER OF PLOTs : " << std::flush;
  std::cin >> N;
  */

  std::cout << "------------------------------- " << std::endl;

  std::string CHIP;
  std::cout << "CHIP : " << std::flush;
  std::cin >> CHIP;

  std::string FET;
  std::cout << "FET  : " << std::flush;
  std::cin >> FET;

  std::string Vd;
  std::cout << "Vd  : " << std::flush;
  std::cin >> Vd;

  std::string TEMP;
  std::cout << "TEMPERATURE (E:END)----- " << std::endl;

  float VG[N][NUM_DATA];
  float ID[N][NUM_DATA];

  TCanvas* c=new TCanvas("c","IV Plot", 800, 700);
  c->Draw();
  c->SetBorderMode(0);
  c->SetLogy(1);
  c->SetGridx();
  c->SetGridy();

  c->SetFillColor(0);
  gStyle->SetTitleFillColor(0);
  gStyle->SetTitleBorderSize(1);
  
  c->SetFrameBorderMode(0);

  TLegend *leg = new TLegend(0.13, 0.70, 0.27, 0.88,"TEMPERATURE","NDC");
  leg->SetTextSize(0.03);
  leg->SetBorderSize(0);
  leg->SetFillStyle(0);
  leg->SetFillColor(0);

  TMultiGraph *mg= new TMultiGraph();  
  TGraph *g[N];

  for(int ii=0; ii<N; ii++){

    char T[3][40]={"room","3K","E"};


    //  std::cin >> TEMP;
    TEMP=T[ii];

    if(TEMP=="E")
      break;

    std::string SOISTJ="PTEG2"; //SOISTJ3の場合
    //std::string SOISTJ="SOISTJ2"; //SOISTJ2の場合
    //std::string SOISTJ="SOISTJ4"; //SOISTJ4の場合
    std::string IV="IdVg";
    std::string _="_";
    std::string EXT=".txt";
    std::string CHIP_FET_IV_Vd_=CHIP+_+FET+_+IV+_+Vd+_;

    std::string FileName = SOISTJ+_+CHIP_FET_IV_Vd_+TEMP+_+EXT;
    std::ifstream ifs(FileName.c_str());

    std::string str;

    int iii=0;
    while(getline(ifs,str))
      {

      sscanf(str.c_str(),"%*f,%*f,%f ,%*f ,%f,%*f,%*f,%*f,%*[^,],%*[a-zA-Z0-9: ]",
	     &VG[ii][iii],&ID[ii][iii]); 

      ID[ii][iii]=fabs(ID[ii][iii]);
      //cout << "VG = " << VG[ii][iii] <<flush;
      //cout << "ID = " << ID[ii][iii] <<endl;    //test
      iii++;

      }

    g[ii] = new TGraph(iii,VG[ii],ID[ii]);
    g[ii]->SetMarkerStyle(20);
    g[ii]->SetMarkerColor(ii+2);
    g[ii]->SetName(TEMP.c_str());

    leg->AddEntry(g[ii],TEMP.c_str(),"P");
    
    mg->Add(g[ii]);

  }

  mg->Draw("AP");

  gROOT->GetColor(3)->SetRGB(0., 0.7, 0.); // Green  (0, 1, 0)->(0, 0.7, 0)
  gROOT->GetColor(5)->SetRGB(1., 0.5, 0.);
  gROOT->GetColor(6)->SetRGB(0., 0.8, 1.);
  //std::string TITLE ="SOISTJ2 "+CHIP+FET+" Vd="+Vd+"V"; //SOISTJ2の場合
  std::string TITLE ="PTEG2 "+CHIP+FET+" Vd="+Vd+"V"; //SOISTJ3の場合
  
  mg->SetTitle(TITLE.c_str());
  mg->GetXaxis()->SetTitle("Vgs [V]");
  mg->GetYaxis()->SetTitle("Ids [A]"); 
  mg->GetYaxis()->SetTitleOffset(1.2);

  //mg->SetMinimum(1e-13);
  // mg->SetMaximum(5e-4);

  //x軸の設定                                                                   
  //mg->GetXaxis()->SetLimits(0, 1.0);
  //mg->GetXaxis()->SetLimits(-1.0, 0); /*for PMOS*/

  leg->Draw();

  std::cout << "------------------------------ "<<std::endl;

 
  std::string EPS=".eps";
  std::string SName=SOISTJ+_+CHIP_FET_IV_Vd_+EPS;
  c->SaveAs(SName.c_str());
  //std::string GIF=".gif";
  //std::string SName=SOISTJ+_+CHIP_FET_IV_Vd_+GIF;
  //c->SaveAs(SName.c_str());

}
