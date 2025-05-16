var a = "", b = "", c = "", x = "", op = 0, tempp = "";
function showMsg(temp) {
    x = temp;
    op = 1;
    tempp = tempp + x;
    document.getElementById("demo").innerHTML = tempp;
}
function calculate() {
    if (x == '+') { c = parseInt(a) + parseInt(b); }
    else if (x == '-') { c = parseInt(a) - parseInt(b); }
    else if (x == '*') { c = parseInt(a) * parseInt(b); }
    else if (x == '/') { c = parseInt(a) / parseInt(b); }
    else if (x == '^') { c = Math.pow(a, b); }
    else if (x == '%') { c = (parseInt(a) / parseInt(b)) * 100; c = c + '%'; }
    tempp = tempp + "=" + c;
    document.getElementById("demo").innerHTML = tempp;
    tempp = ""; a = ""; b = ""; op = 0;
}
function getnum(temp) {
    if (op == 0) {
        a = a + temp;
        tempp = tempp + a;
    }
    else {
        b = b + temp;
        tempp = tempp + b;
    }
    document.getElementById("demo").innerHTML = tempp;
}
function clear() {

    a = ""; b = ""; c = ""; op = 0; tempp = ""; alert(a); document.getElementById("demo").innerHTML = tempp;
}