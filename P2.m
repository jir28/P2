close all; clear; clc;

%Valores del circuito
R = 47e3; 
C = 10e-6;
alpha = -1/R/C;
t_teo = (0:0.01:5)'; %vector de tiempo
y_teo = 5*(1-exp(alpha*t_teo)); %ecuacion que modela al sistema 
fc = 5/1023; %factor de conversion para obtener datos de arduino en voltaje 
ts = 0.01; %tiempo de muestreo
RC = load('RC.mat'); %carga de datos experimentales
y = RC.RC1(:,2)*fc; %salida del sistema experimental
m = length(u); %longitud de las muestras
t = ts * (0:m-1)'; %intervalo de tiempo de datos experimentales
%comparacion grafica
figure(1)
hold on
grid on
plot(t_teo,y,'.r','MarkerSize',12,'DisplayName','Voltaje experimental');
plot(t_teo,y_teo,'b','LineWidth',2,'DisplayName','Voltaje teórico');
xlabel('Voltaje de salida [V]')
ylabel('Tiempo [s]')
title('Comparación entre voltaje de salida de circuito RC teórico y experimental')
legend