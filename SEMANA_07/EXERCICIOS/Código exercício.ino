#include <WiFi.h>
#include <WiFiClient.h>
#include <WiFiAP.h>
#include <WebServer.h>

const char* ssid = "EspG";
const char* password = "Giovane123";

#define led2 16
#define led1 42

WebServer server(80);

void setup() {
  Serial.begin(9600);
  delay(1000);

  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);

  WiFi.softAP(ssid, password);
  IPAddress IP = WiFi.softAPIP();

  Serial.print("Endereço IP: ");
  Serial.println(IP);

  server.begin();

  server.on("/", handleRoot);
  server.on("/jogador1", handle1_1);  //começa a "campanha" do jogador 1
  server.on("/jogador2", handle1_2);  //começa a "campanha" do jogador 2
  server.on("/segundaE1_1", handleE1_1);   //errou a primeira, jogador 1
  server.on("/segundaA1_1", handleA1_1);   //acertou a primeira, jogador 1
  server.on("/terceiraE2_1", handleE2_1);  //errou a segunda, jogador 1
  server.on("/terceiraA2_1", handleA2_1);  //acertou a segunda, jogador 1
  server.on("/segundaE1_2", handleE1_2);   //errou a primeira, jogador 2
  server.on("/segundaA1_2", handleA1_2);   //acertou a primeira, jogador 2
  server.on("/terceiraE2_2", handleE2_2);  //errou a segunda, jogador 2
  server.on("/terceiraA2_2", handleA2_2);  //acertou a segunda, jogador 2
  server.on("/finalE3_1", handleE3_1);
  server.on("/finalA3_1", handleA3_1);
  server.on("/finalE3_2", handleE3_2);
  server.on("/finalA3_2", handleA3_2);
  server.on("/vencedor", handleVencedor);  //mostra o vencedor
}

int pontos1 = 0;
int pontos2 = 0;

void handleRoot() {
  pontos1 = 0;
  pontos2 = 0;
  String html = "";
  html += "<meta charset='UTF-8'>";
  html += "<h1><b>Quiz negócios e design thinking</b></h1>";
  html += "<h3><a href=\"/jogador1\">jogador 1</a></h3><br>";
  html += "<h3><a href=\"/jogador2\">jogador 2</a></h3><br>";
  server.send(200, "text/html", html);
}

int aumentarPontos(int jogador) {
  jogador += 1;
  return jogador;
}

void handle1_1() {
  String html = "";
  html += "<meta charset='UTF-8'>";
  html += "<h1>O que é público-alvo?</h1><br>";
  html += "<a href=\"/segundaE1_1\">A. Quem desenvolve o produto</a><br>";
  html += "<a href=\"/segundaE1_1\">B. Empreendedor</a><br>";
  html += "<a href=\"/segundaA1_1\">C. Potenciais clientes</a><br>";
  html += "<a href=\"/segundaE1_1\">D. Investidores</a><br>";
  server.send(200, "text/html", html);
}

void handleE1_1() {
  String html = "";
  html += "<meta charset='UTF-8'>";
  html += "<h1>O que é equity?</h1><br>";
  html += "<a href=\"/terceiraE2_1\">A. Ativos gerais da empresa</a><br>";
  html += "<a href=\"/terceiraE2_1\">B. Lucro da empresa</a><br>";
  html += "<a href=\"/terceiraE2_1\">C. Imposto</a><br>";
  html += "<a href=\"/terceiraA2_1\">D. Valor da empresa</a><br>";
  server.send(200, "text/html", html);
}

void handleA1_1() {
  String html = "";
  html += "<meta charset='UTF-8'>";
  html += "<h1>O que é equity?</h1><br>";
  html += "<a href=\"/terceiraE2_1\">A. Ativos gerais da empresa</a><br>";
  html += "<a href=\"/terceiraE2_1\">B. Lucro da empresa</a><br>";
  html += "<a href=\"/terceiraE2_1\">C. Imposto</a><br>";
  html += "<a href=\"/terceiraA2_1\">D. Valor da empresa</a><br>";
  server.send(200, "text/html", html);
  pontos1 = aumentarPontos(pontos1);
}

void handleE2_1() {
  String html = "";
  html += "<meta charset='UTF-8'>";
  html += "<h1>O que é market-fit?</h1><br>";
  html += "<a href=\"/finalA3_1\">A. Parte do mercado que sua empresa possui </a><br>";
  html += "<a href=\"/finalE3_1\">B. Produto que o mercado entende como útil e está disposto a comprar</a><br>";
  html += "<a href=\"/finalE3_1\">C. Parte da empresa para cada sócio</a><br>";
  html += "<a href=\"/finalE3_1\">D. Lucro da empresa</a><br>";
  server.send(200, "text/html", html);
}

void handleA2_1() {
  String html = "";
  html += "<meta charset='UTF-8'>";
  html += "<h1>O que é market-fit?</h1><br>";
  html += "<a href=\"/finalA3_1\">A. Parte do mercado que sua empresa possui </a><br>";
  html += "<a href=\"/finalE3_1\">B. Produto que o mercado entende como útil e está disposto a comprar</a><br>";
  html += "<a href=\"/finalE3_1\">C. Parte da empresa para cada sócio</a><br>";
  html += "<a href=\"/finalE3_1\">D. Lucro da empresa</a><br>";
  server.send(200, "text/html", html);
  pontos1 = aumentarPontos(pontos1);
}

void handleE3_1() {
  digitalWrite(led1, HIGH);
  String html = "";
  html += "<meta charset='UTF-8'>";
  html += "<h2><a href=\"/vencedor\">Revelar vencedor</a></h2><br>";
  server.send(200, "text/html", html);
}

void handleA3_1() {
  digitalWrite(led1, HIGH);
  String html = "";
  html += "<meta charset='UTF-8'>";
  html += "<h2><a href=\"/vencedor\">Revelar vencedor</a></h2><br>";
  server.send(200, "text/html", html);
  pontos1 = aumentarPontos(pontos1);
}

void handle1_2() {
  String html = "";
  html += "<meta charset='UTF-8'>";
  html += "<h1>O que é público-alvo?</h1><br>";
  html += "<a href=\"/segundaE1_2\">A. Quem desenvolve o produto</a><br>";
  html += "<a href=\"/segundaE1_2\">B. Empreendedor</a><br>";
  html += "<a href=\"/segundaA1_2\">C. Potenciais clientes</a><br>";
  html += "<a href=\"/segundaE1_2\">D. Investidores</a><br>";
  server.send(200, "text/html", html);
}

void handleE1_2() {
  String html = "";
  html += "<meta charset='UTF-8'>";
  html += "<h1>O que é equity?</h1><br>";
  html += "<a href=\"/terceiraE2_2\">A. Ativos gerais da empresa</a><br>";
  html += "<a href=\"/terceiraE2_2\">B. Lucro da empresa</a><br>";
  html += "<a href=\"/terceiraE2_2\">C. Imposto</a><br>";
  html += "<a href=\"/terceiraA2_2\">D. Valor da empresa</a><br>";
  server.send(200, "text/html", html);
}

void handleA1_2() {
  String html = "";
  html += "<meta charset='UTF-8'>";
  html += "<h1>O que é equity?</h1><br>";
  html += "<a href=\"/terceiraE2_2\">A. Ativos gerais da empresa</a><br>";
  html += "<a href=\"/terceiraE2_2\">B. Lucro da empresa</a><br>";
  html += "<a href=\"/terceiraE2_2\">C. Imposto</a><br>";
  html += "<a href=\"/terceiraA2_2\">D. Valor da empresa</a><br>";
  server.send(200, "text/html", html);
  pontos2 = aumentarPontos(pontos2);
}

void handleE2_2() {
  String html = "";
  html += "<meta charset='UTF-8'>";
  html += "<h1>O que é market-fit?</h1><br>";
  html += "<a href=\"/finalA3_2\">A. Parte do mercado que sua empresa possui </a><br>";
  html += "<a href=\"/finalE3_2\">B. Produto que o mercado entende como útil e está disposto a comprar</a><br>";
  html += "<a href=\"/finalE3_2\">C. Parte da empresa para cada sócio</a><br>";
  html += "<a href=\"/finalE3_2\">D. Lucro da empresa</a><br>";
  server.send(200, "text/html", html);
}

void handleA2_2() {
  String html = "";
  html += "<meta charset='UTF-8'>";
  html += "<h1>O que é market-fit?</h1><br>";
  html += "<a href=\"/finalA3_2\">A. Parte do mercado que sua empresa possui </a><br>";
  html += "<a href=\"/finalE3_2\">B. Produto que o mercado entende como útil e está disposto a comprar</a><br>";
  html += "<a href=\"/finalE3_2\">C. Parte da empresa para cada sócio</a><br>";
  html += "<a href=\"/finalE3_2\">D. Lucro da empresa</a><br>";
  pontos2 = aumentarPontos(pontos2);
}

void handleE3_2() {
  digitalWrite(led2, HIGH);
  String html = "";
  html += "<meta charset='UTF-8'>";
  html += "<h2><a href=\"/vencedor\">Revelar vencedor</a></h2><br>";
  server.send(200, "text/html", html);
}

void handleA3_2() {
  digitalWrite(led2, HIGH);
  String html = "";
  html += "<meta charset='UTF-8'>";
  html += "<h2><a href=\"/vencedor\">Revelar vencedor</a></h2><br>";
  server.send(200, "text/html", html);
  pontos2 = aumentarPontos(pontos2);
}

void handleVencedor() {
  digitalWrite(led1,LOW);
  digitalWrite(led2,LOW);
  if (pontos2 > pontos1) {
    String html = "";
    html += "<meta charset='UTF-8'>";
    html += "<h1>Jogador 2 ganhou!</h1><br>";
    html += "<h1><a href=\"/\">Jogar Novamente</a></h1>";
    server.send(200, "text/html", html);
  } else if (pontos1 > pontos2) {
    String html = "";
    html += "<meta charset='UTF-8'>";
    html += "<h1>Jogador 1 ganhou!</h1><br>";
    html += "<h1><a href=\"/\">Jogar novamente</a></h1>";
    server.send(200, "text/html", html);
  } else {
    String html = "";
    html += "<meta charset='UTF-8'>";
    html += "<h1>Empate!</h1><br>";
    html += "<h1><a href=\"/\">Jogar novamente</a></h1>";
    server.send(200, "text/html", html);
  }
}

void loop() {
  server.handleClient();
  delay(2);
}