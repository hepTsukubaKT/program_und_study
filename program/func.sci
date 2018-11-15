clear;
lambda=45
d=50

// *** データの作成 a**
X = linspace(-180,180,360);
//Y = log(X);
// *** 解くべき関数の定義 ***
function  y=func(x)
   y=asind((80-x*sind(45))/x)-asind((40-x*sind(45))/x)-8;
endfunction
Y=func(X)
// *** 非線形方程式ソルバ  ***
yp = 0;		// yp = f(x)
x0 = 1000;		// ソルバ―の初期値
// 非線形方程式を解く
xp = fsolve(x0, func)
// 誤差
//err = abs(xp - exp(yp))

// *** グラフのプロット ***
plot(X,  Y,  '-b');
plot(X,  X*0, '--k');
plot(xp, yp, 'or');
//plot()
