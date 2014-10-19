Gestion-robot-A20-Olinuxino-Micro
=================================

Utilisation de Wt (Witty) pour gerer le robot sur chassis Olimex et avec la carte A20 Olinuxino Micro.

Il faut installer Wt sur la carte Olinuxino. 

compilation : g++ -o robot robot.cpp  -lwthttp -lwt -lboost_signals

utilisation : ./robot --docroot . --http-address 10.11.0.107   --http-port 9090

Il faut évidement changer l'adresse IP, par celui de la carte OLinuxino.

On se connecte sur le serveur par http://10.11.0.107 :9090/
