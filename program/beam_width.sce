//////////////
//define    //
//////////////
//カレントディレクトリ設定
cd 'C:\Users\tsuku\Documents\program_und_study\program'

//回折格子の溝幅
d=0.05//[mm]
d_um=50//[um]
//ブレーズアングル
theta_b=26.45
//溝数
N=1/d//[/mm]
//回折格子から焦電検出器までの距離
leng=350//[mm]

//////////////
//variable  //
//////////////
//入射波長
lambda=47.6//[um]
inc_width=10.344//[mm]
//入射角
alpha=[45 60 65 70 75]
//ファイル名
fd=mopen('dat\exp476.dat')
//ブレーズの高さ
d_h=d*sind(theta_b)//[mm]


///////////////////
//data reading  //
//////////////////
header=mgetl(fd,1);
data=mfscanf(-1,fd,"%f%f%f%f%f%f");
//data=fscanfMat(fd)
disp(data,"read data is ")
mclose(fd)

//alpha=data(:,1)'
//disp(alpha)
////////////////////////////////////////
//回折角の計算                        //
////////////////////////////////////////
function[beta_b ]=col_beta(alpha,d_um)
    beta_b=asind((lambda-d_um*sind(alpha))/d_um)//[deg.]
endfunction
///////////////////////////////////////
//光路長によるビームの広がりの計算  //
///////////////////////////////////////
function[parsent]=col_l(alpha,beta_b,d) 
    //光路長 
    x=d_h/cosd(alpha-theta_b)//[mm]
    l=x*sind(alpha+beta_b)//[mm]
    //50umに対する回折ビームの幅
    d_width=d+l
    parsent=d_width/d
endfunction
//////////////////////////////////////////
//回折格子の分解能によるビームの広がり  //
//////////////////////////////////////////
function[beam_corr]=col_beam_corr(alpha,N,inc_width,d_um,leng)
    //回折ビームの幅
    //分解能による広がり
    d_lambda=lambda/(N*(inc_width/cosd(alpha)))
    //分解能による広がり角
    db=asind((lambda+d_lambda-d_um*sind(alpha))/d_um)-asind((lambda-d_um*sind(alpha))/d_um)
    //分解能による広がり幅
    width=leng*tand(db)
    //分解能による回折光の広がり
    beam_width=width*2+(inc_width/cosd(alpha)*cosd(asind((lambda-d_um*sind(alpha))/d_um)))
    //補正係数
    beam_corr=beam_width/inc_width
endfunction

b_b=0
wid_par=0
beam_crr=zeros(5)
cor_pow1=zeros(5)
disp(lambda,"lambda")
disp("/************************/")
for i=1:length(alpha)
    //disp(alpha(i),"input angle")
    [b_b]=col_beta(alpha(i),d_um)
    //[wid_par]=col_l(alpha(i),b_b,d_um)
    [beam_crr(i)]=col_beam_corr(alpha(i),N,inc_width,d_um,leng)
    //disp(alpha(i))
    //disp(wid_par)
    //disp(beam_crr(i),"beam_corr")
    disp(beam_crr(i))
    cor_pow1(i)=beam_crr(i)*data(i,4)
    disp(data(i,4),"raw data is")
    disp(cor_pow1(i),"correct value is")
end
disp(cor_pow1)
