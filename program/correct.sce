alpha =[45 60 65 70 75]
lambda=70.5
inc_width=12.356
leng=350
//defined from grating
d=50
N=20
//col
d_lambda=lambda/(N*inc_width)
db=asind((lambda+d_lambda-d*sind(alpha))/d)-asind((lambda-d*sind(alpha))/d)

width=leng*tand(db)

beam_width=width*2+inc_width

beam_corr=beam_width/inc_width

disp(d_lambda)
disp(beam_width)
disp(beam_corr)
