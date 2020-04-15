#include <stdio.h>
#include <string.h>


#define ESTACIONAMENTO_MAX_TAM        (10)
#define PLACA_NULL                    (-1)
#define SUCESSO                       (0)
#define ERRO_ESTACIONAMENTO_CHEIO     (-1)
#define ERRO_MANOBRA_INVALIDA         (-2)


typedef enum manobra_e manobra_t;
typedef struct veiculo_s veiculo_t;
typedef struct estacionamento_s estacionamento_t;


enum manobra_e
{
    manobEntrada,
    manobSaida
};


struct veiculo_s
{
    int placa;
};


struct estacionamento_s
{
    veiculo_t vaga[ ESTACIONAMENTO_MAX_TAM ];
    int qtd;
};


void estacionamento_inicializar( estacionamento_t * e )
{
    memset( e, 0, sizeof(estacionamento_t) );
}


int estacionamento_push( estacionamento_t * e, veiculo_t v )
{
    if( e->qtd == ESTACIONAMENTO_MAX_TAM )
        return ERRO_ESTACIONAMENTO_CHEIO;

    e->vaga[ e->qtd++ ] = v;

    return SUCESSO;
}


veiculo_t estacionamento_pop( estacionamento_t * e )
{
    if( e->qtd == 0 )
    {
        veiculo_t v;
        v.placa = PLACA_NULL;
        return v;
    }

    return e->vaga[ --e->qtd ];
}


int estacionamento_manobrar_veiculo( estacionamento_t * e, manobra_t m, int placa )
{
    switch( m )
    {
        case manobEntrada :
        {
            veiculo_t v;
            v.placa = placa;

            if( estacionamento_push( e, v ) == ERRO_ESTACIONAMENTO_CHEIO )
                return ERRO_ESTACIONAMENTO_CHEIO;

            return 1;
        }

        case manobSaida :
        {
            veiculo_t v;
            estacionamento_t aux;
            int qtd_manobras = 0;

            estacionamento_inicializar( &aux );

            while(1)
            {               
                v = estacionamento_pop( e );

                if( v.placa == PLACA_NULL )
                    break;

                qtd_manobras++;

                if( v.placa == placa )
                    break;

                estacionamento_push( &aux, v );
            }

            while(1)
            {               
                v = estacionamento_pop( &aux );

                if( v.placa == PLACA_NULL )
                    break;

                estacionamento_push( e, v );
            }

            return qtd_manobras;
        }

        default :
        {
            return ERRO_MANOBRA_INVALIDA;
        }
    }
}

void estacionamento_listar_veiculos( estacionamento_t * e )
{
    int i = 0;

    if( !e->qtd )
    {
        printf("Estacionamento Vazio!\n");
        return;
    }

    printf( "Estacionamento:\n" );

    for( i = 0; i < e->qtd; i++ )
        printf( "   Vaga %d / Placa: %d\n", i, e->vaga[i].placa );
}


int main( int argc, char * argv[] )
{
    int qtd = 0;
    estacionamento_t e;

    estacionamento_inicializar( &e );

    estacionamento_listar_veiculos( &e );

    estacionamento_manobrar_veiculo( &e, manobEntrada, 1010 );
    estacionamento_manobrar_veiculo( &e, manobEntrada, 2020 );
    estacionamento_manobrar_veiculo( &e, manobEntrada, 3030 );
    estacionamento_manobrar_veiculo( &e, manobEntrada, 4040 );
    estacionamento_manobrar_veiculo( &e, manobEntrada, 5050 );

    estacionamento_listar_veiculos( &e );

    qtd = estacionamento_manobrar_veiculo( &e, manobSaida, 3030 );

    printf( "Retirei veiculo do estacionamento com %d manobras!\n", qtd );

    estacionamento_listar_veiculos( &e );

    return 0;
}

/* fim-de-arquivo */
