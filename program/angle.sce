//TEのみ
n=[0 1 2]
deg_alpha=-45
//lambda=[43.7 77.3 86.7]
lambda=[41.4 52.9 57.2 70.5]
d=50
ref0=zeros(length(lambda))
ref1=zeros(length(lambda))
ref2=zeros(length(lambda))
//for j=deg_alpha:0:5
       for i=1:length(lambda)
         ref0(i)=asind((n(1)*lambda(i)+d*sind(deg_alpha))/d)
         ref1(i)=asind((1*lambda(i)+d*sind(deg_alpha))/d)
         //ref2(i)=asind((n(3)*lambda(i)+d*sind(deg_alpha))/d)
         //disp(deg_alpha,"input degree is")
         //disp(ref0,"0 order light is")
         //disp(ref1,"1 order light is")
         //disp(ref2,"2 order light is")
       end
//end
//ref0=asind((n(1)*lambda-d*sind(deg_alpha))/d)
//ref1=asind((n(2)*lambda-d*sind(deg_alpha))/d)
