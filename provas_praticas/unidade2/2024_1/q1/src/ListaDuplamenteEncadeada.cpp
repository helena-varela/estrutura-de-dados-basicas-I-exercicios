//
//  ListaDuplamenteEncadeada.cpp
//
//  Criado por Eiji Adachi Medeiros Barbosa
//

#include "../header/ListaDuplamenteEncadeada.h"
#include <string>
#include <sstream>

#include "../header/ListaDuplamenteEncadeada.h" // ajuste o caminho se o .h estiver em "include" ou "header"

// Construtor: Aloca as sentinelas e amarra uma na outra
ListaDuplamenteEncadeada::ListaDuplamenteEncadeada(void) {
    this->cabeca = new No<std::string>("");
    this->cauda = new No<std::string>("");
    
    this->cabeca->setProximo(this->cauda);
    this->cauda->setAnterior(this->cabeca);
    
    this->quantidade = 0;
}

// Destrutor: Limpa todos os nós reais da memória e as sentinelas
ListaDuplamenteEncadeada::~ListaDuplamenteEncadeada(void) {
    No<std::string>* atual = this->cabeca;
    while (atual != nullptr) {
        No<std::string>* proximo = atual->getProximo();
        delete atual;
        atual = proximo;
    }
    this->cabeca = nullptr;
    this->cauda = nullptr;
    this->quantidade = 0;
}

No<std::string>* ListaDuplamenteEncadeada::getCabeca(void) {
    return this->cabeca;
}

No<std::string>* ListaDuplamenteEncadeada::getCauda(void) {
    return this->cauda;
}

bool ListaDuplamenteEncadeada::vazia(void) {
    return this->quantidade == 0;
}

int ListaDuplamenteEncadeada::tamanho(void) {
    return this->quantidade;
}

// Formata a string no padrão exigido: "A<->B<->C"
std::string ListaDuplamenteEncadeada::imprimir(void) {
    if (vazia()) return "";

    std::string resultado = "";
    No<std::string>* atual = this->cabeca->getProximo();

    while (atual != this->cauda) {
        resultado += atual->getValor();
        if (atual->getProximo() != this->cauda) {
            resultado += "<->";
        }
        atual = atual->getProximo();
    }
    return resultado;
}

// Método interno do professor adaptado perfeitamente para a enumeração dele
StatusDaLista ListaDuplamenteEncadeada::checarConsistencia(void) {
    if (this->cabeca == nullptr) return CABECA_NULA;
    if (this->cauda == nullptr) return CAUDA_NULA;
    
    if (this->cabeca->getAnterior() != nullptr) return CABECA_ANTERIOR;
    if (this->cabeca->getProximo() == nullptr) return CABECA_PROXIMO_NULO;
    
    if (this->cauda->getProximo() != nullptr) return CAUDA_PROXIMO;
    if (this->cauda->getAnterior() == nullptr) return CAUDA_ANTERIOR_NULO;
    
    if (vazia()) {
        if (this->cabeca->getProximo() == this->cauda && this->cauda->getAnterior() == this->cabeca) {
            return OK;
        }
        return CABECA_CAUDA;
    }

    No<std::string>* atual = this->cabeca;
    int contagem = 0;

    while (atual->getProximo() != this->cauda && atual->getProximo() != nullptr) {
        No<std::string>* prox = atual->getProximo();
        if (prox->getAnterior() != atual) {
            return ENCADEAMENTO_INCORRETO;
        }
        atual = prox;
        contagem++;
    }

    if (atual->getProximo() != this->cauda) return CABECA_CAUDA;
    if (contagem != this->quantidade) return ENCADEAMENTO_INCORRETO;

    return OK;
}

// Método auxiliar usado pelos testes para validar o ordenamento correto
bool ListaDuplamenteEncadeada::checarOrdenacao(void) {
    if (this->quantidade <= 1) return true;

    No<std::string>* atual = this->cabeca->getProximo();
    while (atual->getProximo() != this->cauda) {
        No<std::string>* prox = atual->getProximo();
        // Na ordem decrescente, o atual deve ser MAIOR que o próximo
        if (atual->getValor() < prox->getValor()) {
            return false;
        }
        atual = prox;
    }
    return true;
}

/**
 * @brief Insere @p s em ordem decrescente, mantendo a ordenação.
 * @param s Elemento a ser inserido.
 * @return true se inserido com sucesso, false se já existia.
 */
bool ListaDuplamenteEncadeada::inserirOrdenado(std::string s) {
    No<std::string>* atual = cabeca->getProximo();

    while(atual != cauda && atual->getValor() > s){
        atual = atual->getProximo();
    }

    if (atual != cauda && atual->getValor() == s)
    {
        return false;
    } 

    No<std::string>* novoNo = new No<std::string>(s);
    No<std::string>* noAnterior = atual->getAnterior();

    novoNo->setProximo(atual);
    novoNo->setAnterior(noAnterior);

    atual->setAnterior(novoNo);
    noAnterior->setProximo(novoNo);

    quantidade++;
    return true;
}