// Max number of candidates
const MAX = 9;

//Variável para contabilizar número de votos
let totalVotos = 0;

//Array for candidates
const candidatos = [];

// Candidates have name and vote count
class Candidato {
  constructor(name, votes, eliminado) {
    this.name = name;
    this.votes = votes;
    this.eliminado = eliminado = false;
  }
}

//Função para criar candidatos
const candidatoCreator = (nome_candidatos) => {
  if (nome_candidatos.length > MAX) {
    console.log("Número de candidatos invalidado para realizar a eleição");
    return;
  } else {
    nome_candidatos.forEach((nome) => {
      //Criando candidato e adicionando no array
      candidatos.push(new Candidato(nome, 0));
      return console.log(`Candidato ${nome} criado com sucesso!!`);
    });
  }
};

//Função para votar

//Recebe a lista de preferências do eleitor
const votoPorPreferencia = (preferencias) => {
  candidatos.forEach((c) => (c.votes = 0));
  for (let i = 0; i < preferencias.length; i++) {
    for (let j = 0; j < preferencias[i].length; j++) {
      let escolhaPrincipal = preferencias[i][j];

      //find é uma função callback que espera uma função, e retorna um objeto se encontrar, senão undefined
      //If verifica se o valor é nulo ou não-nulo, então para simplificar podemos passar apenas o objeto retornado por find.
      let validarEscolhido = candidatos.find(
        (c) => c.name === escolhaPrincipal && !c.eliminado
      );

      if (validarEscolhido) {
        console.log(`Voto válidado para o candidato ${validarEscolhido.name}`);
        validarEscolhido.votes++;
        totalVotos++;
        break;
      }
    }
  }
};
//Função para eliminar
const eliminarCandidato = () => {
  let menorVotoEncontrado = Infinity;

  // Passo 1: Encontrar o menor número de votos entre os não eliminados
  candidatos.forEach((c) => {
    if (!c.eliminado && c.votes < menorVotoEncontrado) {
      menorVotoEncontrado = c.votes;
    }
  });

  // Passo 2: Eliminar todos que tiverem esse menor número de votos
  candidatos.forEach((c) => {
    if (!c.eliminado && c.votes === menorVotoEncontrado) {
      c.eliminado = true;
      console.log(`Candidato ${c.name} eliminado com ${c.votes} votos.`);
    }
  });
};

//Função que verifica o resultado

const verificarResultado = (participantes) => {
  for (let c of candidatos) {
    if (!c.eliminado && c.votes > participantes.length / 2) {
      console.log(`Vencedor da eleição ${c.name}`);
      return true;
    }
  }
  return false;
};

//Função para executar  o algoritmo de Runoff/A eleição
const executarEleicao = (preferencias) => {
  while (true) {
    if (verificarResultado(preferencias)) {
      break;
    }

    eliminarCandidato();
  }
};

//Inputs para testar as funções

candidatoCreator(["Caio", "Ribamar", "Pedro"]);
const votos = [
  ["Ribamar", "Caio", "Pedro"],
  ["Ribamar", "Caio", "Pedro"],
  ["Caio", "Pedro", "Caio"],
  ["Caio", "Pedro", "Ribamar"],
  ["Pedro", "Caio", "Ribamar"],
];
executarEleicao(votos);
