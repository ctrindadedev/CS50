class dicionarioHash {
  constructor() {
    this.N = 127;
    this.table = Array.from({ length: this.N }, () => []);
    this.totalPalavras = 0;
  }

  //Converte uma palavra para um número (índice)
  _hash(key) {
    let hash = 0;
    for (let i = 0; i < key.length; i++) {
      //charCode utiliza o código ASCII dos caracteres
      hash += key.charCodeAt(i);
    }
    return hash % this.table.length;
  }
  //Carrega palavras do dicionário em memória (nos buckets)
  load(listaDePalavras) {
    try {
      for (const palavra of listaDePalavras) {
        const index = this._hash(palavra.toLowerCase());
        if (!this.table[index].includes(palavra.toLowerCase())) {
          this.table[index].push(palavra.toLowerCase());
          this.totalPalavras++;
        }
      }
      return true;
    } catch {
      return false;
    }
  }
  //Verifica se a palavra existe na tabela
  check(palavra) {
    const index = this._hash(palavra.toLowerCase());
    return this.table[index].includes(palavra.toLowerCase());
  }
  //Retorna quantas palavras foram carregadas no dicionário
  size() {
    return this.totalPalavras;
  }
  //Limpa a memória (zera a tabela)
  unload() {
    this.table = Array.from({ length: this.N }, () => []);
    this.totalPalavras = 0;
    return true;
  }

  //Algumas implementações para entender como funciona os metódos da Hashtable já nativa do JS (Map)

  set(key, value) {
    const index = this._hash(key);
    if (this.table[index]) {
      for (let i = 0; i < this.table[index].length; i++) {
        if (this.table[index][i][0] === key) {
          this.table[index][i][1] = value;
          return;
        }
      }
      this.table[index].push([key, value]);
    } else {
      this.table[index] = [];
      this.table[index].push([key, value]);
    }
    this.size++;
  }

  get(key) {
    const index = this._hash(key);
    if (this.table[index]) {
      for (let i = 0; i < this.table.length; i++) {
        if (this.table[index][i][0] === key) {
          return this.table[index][i][1];
        }
      }
    }
    return undefined;
  }

  remove(key) {
    const index = this._hash(key);

    if (this.table[index] && this.table[index].length) {
      for (let i = 0; i < this.table.length; i++) {
        if (this.table[index][i][0] === key) {
          this.table[index].splice(i, 1);
          this.size--;
          return true;
        }
      }
    } else {
      return false;
    }
  }

  display() {
    this.table.forEach((values, index) => {
      const chainedValues = values.map(
        ([key, value]) => `[ ${key}: ${value} ]`
      );
      console.log(`${index}: ${chainedValues}`);
    });
  }
}

module.exports = dicionarioHash;
