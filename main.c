#include <stdio.h>

void tablaprint();

int main(){
	int i,j,x,y,gd_x,gd_y,gl_x,gl_y,tabla[8][8] = {{0,0,0,0,0,0,0,0},
			    {0,0,0,0,0,0,0,0},
			    {0,0,0,0,0,0,0,0},  // gd - gore desno
			    {0,0,0,0,0,0,0,0},  // gl - gore levo
			    {0,0,0,0,0,0,0,0},
			    {0,0,0,0,0,0,0,0},
			    {0,0,0,0,0,0,0,0},
			    {0,0,0,0,0,0,0,0}};
	void tablaprint(){
	    printf("\n");
		for(i=0;i<8;i++){
			for(j=0;j<8;j++){
				printf("%d ",tabla[i][j]);
			}
			printf("\n");
		}
	}

	printf("Unesi koordinate kraljice: ");
	scanf("%d%d",&x,&y);
	tabla[x][y] = 2;

	j=y;					    //
	for(i=0;i<8;i++){			//
		if(i!=x){			    //
			tabla[i][j] = 1;	//
		}				        //
	}					        //
                                //     UNOS JEDINICA NA HORIZONTALU
	i=x;					    //     I VERTIKALU
	for(j=0;j<8;j++){ 			//
		if(j!=y){			    //
			tabla[i][j] = 1;    //
		}				        //
	}					        //



 	if(x>y){			//
 		gl_x = x-y;		//
 		gl_y = 0;		//	ODREDJIVANJE KOORDINATA GORNJEG
 	}else if(x<y){	    //	LEVOG ELEMENTA
 		gl_x = 0;		//
 		gl_y = y-x;		//
 	}else{				//
 		gl_x = 0;		//
 		gl_y = 0;		//
 	}					//



 	while(gl_x < 8 && gl_y < 8){			//
 		if (!(gl_x == x && gl_y == y)){	    //
	 		tabla[gl_x][gl_y] = 1;		    //
 		}					                //	UNOS JEDINICA NA "GLAVNU"
 		gl_x++;				                //	DIJAGONALU
	 	gl_y++;				                //
 	}						                //


	gd_x = x;			        //
	gd_y = y;			        //
	while(gd_x>0 && gd_y<7){	//	ODREDJIVANJE KOORDINARA GORNJEG
		gd_x--;		            //	DESNOG ELEMENTA
		gd_y++;		            //
	}				            //


	for(i=gd_x;i<=gd_y;i++){				    //
		for(j=gd_y;j>=gd_x;j--){			    //
			if(((i+j)==(x+y)) && i!=x && j!=y){	//	UNOS JEDINICA NA "SPOREDNU"
				tabla[i][j] = 1;		        //	DIJAGONALU
			}					                //
		}						                //
	}							                //

	tablaprint();

	return 0;
}
