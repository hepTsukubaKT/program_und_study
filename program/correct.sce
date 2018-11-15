alpha =[45 60 65 70 75]
lambda=47.6
d_lambda=(0.41/57.2)*lambda
d=50
inc_width=6.53

db=asind((lambda+d_lambda-d*sind(alpha))/d)-asind((lambda-d*sind(alpha))/d)

width=350*tand(db)

beam_width=width*2+inc_width

beam_corr=beam_width/inc_width
