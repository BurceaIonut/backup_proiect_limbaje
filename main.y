%{
    #include <iostream>
    #include <stdio.h>
    #include <string.h>
    using namespace std;
    int yylex();
    int yyerror(const char* msg);
    char msg[500];
    extern FILE *yyin;

    class TVAR
    {
        char* nume;
        float valoare;
        char type;
        TVAR* next;
    public:
        static TVAR* head;
        static TVAR* tail;
        TVAR(char* n, char type, float v = -1);
        TVAR();
        int exists(char* n);
        void add(char *n, char type, float v);
        float getValue(char* n);
        char getType(char* n);
        void setValue(char*n, float v);
        void printVars();
    };
    TVAR* TVAR::head;
    TVAR* TVAR::tail;

    TVAR::TVAR(char* n, char type, float v)
    {
        this->nume = new char[strlen(n) + 1];
        strcpy(this->nume, n);
        this->valoare = v;
        this->type = type;
        this->next = NULL;
    }
    TVAR::TVAR()
    {
        TVAR::head = NULL;
        TVAR::tail = NULL;
    }
    int TVAR::exists(char* n)
    {
        TVAR* tmp = TVAR::head;
        while(tmp != NULL)
        {
            if(strcmp(tmp->nume,n) == 0)
                return 1;
            tmp = tmp->next;
        }
        return 0;
    }
    void TVAR::add(char* n, char type, float v)
    {
        TVAR* elem = new TVAR(n, type, v);
        if(head == NULL)
        {
            TVAR::head = TVAR::tail = elem;
        }
        else
        {
            TVAR::tail->next = elem;
            TVAR::tail = elem;
        }
    }
    float TVAR::getValue(char* n)
    {
        TVAR* tmp = TVAR::head;
        while(tmp != NULL)
        {
            if(strcmp(tmp->nume,n) == 0)
                return tmp->valoare;
            tmp = tmp->next;
        }
        return -1;
    }
    void TVAR::setValue(char* n, float v)
    {
        TVAR* tmp = TVAR::head;
        while(tmp != NULL)
        {
            if(strcmp(tmp->nume,n) == 0)
            {
                tmp->valoare = v;
            }
            tmp = tmp->next;
        }
    }
    void TVAR::printVars()
	{
		cout<<"\nPrinting table of variables...\n";
		TVAR* tmp = TVAR::head;
		while(tmp != NULL)
		{
			cout<<tmp->nume<<"="<<tmp->valoare<<"\n";
			tmp = tmp->next;
		}	  
	}
    char TVAR::getType(char* n)
    {
        TVAR* tmp = TVAR::head;
        while(tmp != NULL)
        {
            if(strcmp(tmp->nume,n) == 0)
                return tmp->type;
            tmp = tmp->next;
        }
        return 'f';
    }

    TVAR* ts = NULL;
%}

%union {
    char *sir; 
    int nr_integer;
    double nr_double;
    float nr_float;
}

%token TKN_INTEGER TKN_DOUBLE TKN_FLOAT
%token <sir> TKN_VAR_NAME 
%token <nr_integer> TKN_INTEGER_NUMBER
%token <nr_double> TKN_DOUBLE_NUMBER 
%token <nr_float> TKN_FLOAT_NUMBER
%token TKN_ERROR
%token TKN_ADD TKN_SUB TKN_MULTIPLICATION TKN_DIVISION TKN_LEFT_PARANTHESIS TKN_RIGHT_PARANTHESIS
%token TKN_IF TKN_WHILE TKN_LEFT_CURLY TKN_RIGHT_CURLY TKN_ELSE
%token TKN_IS_EQUAL TKN_IS_NOT_EQUAL TKN_IS_LOWER TKN_IS_HIGHER TKN_IS_LOWER_OR_EQUAL TKN_IS_HIGHER_OR_EQUAL
%token TKN_DOUBLE_QUOTE TKN_SINGLE_QUOTE TKN_COMMA
%token TKN_PRINT TKN_SCAN
%token TKN_RUN
%token <sir> TKN_FILENAME
%token <sir> TKN_MESSAGE

%type <nr_float> OPERATION
%type <nr_integer> COMPARE

%start START
%left  TKN_ADD TKN_SUB
%left  TKN_MULTIPLICATION TKN_DIVISION
%left  UMINUS
%nonassoc ifx
%nonassoc TKN_ELSE

%%
    START : S
        | S START
        ;
    S : DECLARE_VAR {printf("Passed var declaration/assignment!\n");}
        | OPERATION ';' {printf("Passed operation!\n");}
        | IF {printf("Passed if!\n");}
        | WHILE {printf("Passed while!\n");}
        | PRINT {printf("Print passed!\n");}
        | SCAN {printf("Scan passed!\n");}
        | RUN {printf("Run passed!\n");}
        ;
    DECLARE_VAR : TKN_INTEGER TKN_VAR_NAME '=' OPERATION ';'
        {
            if(!ts->exists($2))
            {
                ts->add($2, 'i', $4);
            }
        }
        | TKN_DOUBLE TKN_VAR_NAME '=' OPERATION ';'
        {
            if(!ts->exists($2))
            {
                ts->add($2, 'd', $4);
            }
        }
        | TKN_FLOAT TKN_VAR_NAME '=' OPERATION ';'
        {
            if(!ts->exists($2))
            {
                ts->add($2, 'f', $4);
            }
        }
        | TKN_VAR_NAME '=' OPERATION ';'
        {
            if(ts->exists($1))
            {
                if(ts->getType($1) == 'i')
                    ts->setValue($1, (int)$3);
                else if(ts->getType($1) == 'd')
                    ts->setValue($1, (double)$3);
                else if(ts->getType($1) == 'f')
                    ts->setValue($1, (float)$3);
            }
            else
            {
                sprintf(msg,"%d:%d Eroare semantica: Variabila %s este utilizata fara sa fi fost declarata!", @1.first_line, @1.first_column, $1);
	    		yyerror(msg);
	    		YYERROR;
            }
        }
        | TKN_INTEGER TKN_VAR_NAME ';'
        {
            if(!ts->exists($2))
            {
                ts->add($2, 'i', 0);
            }
            else
            {
                sprintf(msg,"%d:%d Eroare semantica: Declaratii multiple pentru variabila %s!", @1.first_line, @1.first_column, $2);
				yyerror(msg);
				YYERROR;
            }
        }
        | TKN_DOUBLE TKN_VAR_NAME ';'
        {
            if(!ts->exists($2))
            {
                ts->add($2, 'd', 0);
            }
            else
            {
                sprintf(msg,"%d:%d Eroare semantica: Declaratii multiple pentru variabila %s!", @1.first_line, @1.first_column, $2);
				yyerror(msg);
				YYERROR;
            }
        }
        | TKN_FLOAT TKN_VAR_NAME ';'
        {
            if(!ts->exists($2))
            {
                ts->add($2, 'f', 0);
            }
            else
            {
                sprintf(msg,"%d:%d Eroare semantica: Declaratii multiple pentru variabila %s!", @1.first_line, @1.first_column, $2);
				yyerror(msg);
				YYERROR;
            }
        }
        ;
    OPERATION : OPERATION TKN_ADD OPERATION { $$ = $1 + $3; }
        | OPERATION TKN_SUB OPERATION { $$ = $1 - $3; }
        | OPERATION TKN_DIVISION OPERATION
        { 
            if ($3 != 0)
            {
                $$ = $1 / $3;
            } else {
                fprintf(stderr, "%d.%d: Eroare semantica: Impartire la zero.", @3.first_line, @3.first_column);
                yyerror("Impartire la zero.");
                YYERROR;
            }
        }
        | OPERATION TKN_MULTIPLICATION OPERATION { $$ = $1 * $3; }
        | TKN_SUB OPERATION %prec UMINUS { $$ = -$2; }
        | TKN_INTEGER_NUMBER { $$ = $1; }
        | TKN_DOUBLE_NUMBER { $$ = $1; }
        | TKN_FLOAT_NUMBER { $$ = $1; }
        | TKN_VAR_NAME
        {
            if(ts->exists($1))
            {
                $$ = ts->getValue($1);
            }
        }
        | TKN_LEFT_PARANTHESIS OPERATION TKN_RIGHT_PARANTHESIS
        {
            $$ = $2;
        }
        ;
    IF : TKN_IF TKN_LEFT_PARANTHESIS COMPARE TKN_RIGHT_PARANTHESIS BLOCK %prec ifx
        | TKN_IF TKN_LEFT_PARANTHESIS COMPARE TKN_RIGHT_PARANTHESIS BLOCK TKN_ELSE BLOCK
        ;
    WHILE : TKN_WHILE TKN_LEFT_PARANTHESIS OPERATION TKN_RIGHT_PARANTHESIS TKN_LEFT_CURLY S TKN_RIGHT_CURLY
        | TKN_WHILE TKN_LEFT_PARANTHESIS COMPARE TKN_RIGHT_PARANTHESIS TKN_LEFT_CURLY S TKN_RIGHT_CURLY
        ;
    BLOCK : TKN_LEFT_CURLY S TKN_RIGHT_CURLY
        ;
    COMPARE : OPERATION TKN_IS_EQUAL OPERATION
        {
            if($1 == $3)
            {
                $$ = 1;
            }
            else 
            {
                $$ = 0;
            }
        }
        | OPERATION TKN_IS_NOT_EQUAL OPERATION
        {
            if($1 != $3)
            {
                $$ = 1;
            }
            else 
            {
                $$ = 0;
            }
        }
        | OPERATION TKN_IS_LOWER OPERATION
        {
            if($1 < $3)
            {
                $$ = 1;
            }
            else 
            {
                $$ = 0;
            }
        }
        | OPERATION TKN_IS_HIGHER OPERATION
        {
            if($1 > $3)
            {
                $$ = 1;
            }
            else 
            {
                $$ = 0;
            }
        }
        | OPERATION TKN_IS_LOWER_OR_EQUAL OPERATION
        {
            if($1 <= $3)
            {
                $$ = 1;
            }
            else 
            {
                $$ = 0;
            }
        }
        | OPERATION TKN_IS_HIGHER_OR_EQUAL OPERATION
        {
            if($1 >= $3)
            {
                $$ = 1;
            }
            else 
            {
                $$ = 0;
            }
        }
        ;
    PRINT : TKN_PRINT TKN_LEFT_PARANTHESIS TKN_VAR_NAME TKN_RIGHT_PARANTHESIS ';'
        {
            if(ts->exists($3))
            {
                cout << ts->getValue($3) << "\n";
            }
            else
            {
                sprintf(msg,"%d:%d Eroare semantica: Variabila %s este utilizata fara sa fi fost declarata!", @3.first_line, @3.first_column, $3);
	    		yyerror(msg);
	    		YYERROR;
            }
        }
        | TKN_PRINT TKN_LEFT_PARANTHESIS TKN_MESSAGE TKN_RIGHT_PARANTHESIS ';'
        {
            for(int i = 0; i < strlen($3); i++)
            {
                if($3[i] == '\\' && $3[i + 1] == 'n')
                {
                    cout << endl;
                    i++;
                }
                else if($3[i] == '\\' && $3[i + 1] == 't')
                {
                    cout << '\t';
                    i++;
                }
                else cout << $3[i];
            }
        }
        ;
    SCAN : TKN_SCAN TKN_LEFT_PARANTHESIS TKN_VAR_NAME TKN_RIGHT_PARANTHESIS ';'
        {
            if(ts->exists($3))
            {
                if(ts->getType($3) == 'i')
                {
                    int x;
                    scanf("%d", &x);
                    ts->setValue($3, x);
                }
                else if(ts->getType($3) == 'd')
                {
                    double x;
                    scanf("%lf", &x);
                    ts->setValue($3, x);
                }
                else if(ts->getType($3) == 'f')
                {
                    float x;
                    scanf("%f", &x);
                    ts->setValue($3, x);
                }
            }
            else
            {
                sprintf(msg,"%d:%d Eroare semantica: Variabila %s este utilizata fara sa fi fost declarata!", @3.first_line, @3.first_column, $3);
	    		yyerror(msg);
	    		YYERROR;
            }
        }
        ;
    RUN : TKN_RUN TKN_FILENAME
        {
            yyin = fopen($2, "r");
            yyparse();
            //TODO run; merge doar o data, dupa care se inchide parserul
        }
        ;
%%

int main(int argc, char** argv)
{
    yyparse();
    ts->printVars();
    return 0;
}

int yyerror(const char* error)
{
    printf("Eroare: %s!\n", error);
    return 0;
}