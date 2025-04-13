//Importando funções/₢lasses
const fs = require("fs");
const dicionarioHash = require("./dictionary");
const dicionario = new dicionarioHash();

//Leitura dos arquivos de texto
const palavras = fs
  .readFileSync("dictionaries/large", "utf-8")
  .split("\n")
  .map((p) => p.trim())
  .filter((p) => p.length > 0);

const texto = fs
  .readFileSync("texts/burnett.txt", "utf-8")
  .split(" ")
  .map((p) => p.trim())
  .filter((p) => p.length > 0);

console.log("Carregando dicionário...");
const carregado = dicionario.load(palavras);
console.log("Dicionário carregado?", carregado);
console.log("Total de palavras encontradas:", dicionario.size());

for (const palavra of texto) {
  console.log(
    `"${palavra}":`,
    //Retorna true? Encontrada, senão retorna não encontrada
    dicionario.check(palavra) ? "ENCONTRADA" : "NÃO ENCONTRADA"
  );
}
dicionario.unload();
console.log("Palavras após unload():", dicionario.size());
