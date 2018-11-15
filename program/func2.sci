clear;

// *** データの作成 ***
X = linspace(-180,180,360);
//Y = log(X);

// *** 解くべき関数の定義 ***
function y = func(x)
   y = log(x) - yp;
endfunction

// *** 非線形方程式ソルバ  ***
yp = 1;		// yp = f(x)
x0 = 1;		// ソルバ―の初期値
// 非線形方程式を解く
xp = fsolve(x0, func)
// 誤差
err = abs(xp - exp(yp))

// *** グラフのプロット ***
plot(X,  Y,  '-b');
plot(X,  yp * ones(Y), '--k');
plot(xp, yp, 'or');
