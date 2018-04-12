# include <stdio.h>
# include <conio.h>
# include <stdlib.h>
# include <unistd.h>

struct Table
{
	int pid,bt,wt,tat,prior;
};

int main()
{
  int n,i,n1=0,n2=0,n3=0,p=1,q=1,r=1;
  int total_wt=0,total_tat=0;
  
  int Q1=4; // Quantum time for Inner Round Robin
  int Q=10; // Quantum time for Outer Round Robin
  
  int c1=0,c2=0,c3=0,t=0;
  int pos1,r1;
  
  printf("\n\t              ********************* PROJECT ON SCHEDULING ALGORITHMS ***********************\n");
  
  printf("\n Applying ROUND ROBIN ALGORITHM to the whole System Q1 , Q2 and Q3 (with Quantum time = 10) \n");
  
  printf("\n Priority Range For Queues are given by : \n");
  
  printf("\n \tQ1 : 21 - 30 \t");  printf("(Round Robin Algorithm) => (with Quantum time = 4) \n");
  printf("\n \tQ2 : 11 - 20 \t");  printf("(prior Algorithm) \n");
  printf("\n \tQ3 : 1 - 10 \t");   printf("(First come First Serve Algorithm) \n");
  printf("\n===============================================================================\n");
  
  printf("\n\tEnter the no. of Processes to be Executed : ");
  scanf("%d",&n);
  
  struct Table q1[n],q2[n],q3[n];
  
  // Entering the process number , burst time and priority of each process
  
  for(i=1;i<=n;i++)
  {
  	
  	struct Table obj;    // Creating Object For Structure Table
  	
  	if(i==1)
  	{
  	printf("\n ENTER the values of Process id , BT , Priority for %dst Process :\n ",i);
    }
    else if(i==2)
    {
    printf("\n ENTER the values of Process id , BT , Priority for %dnd Process :\n ",i);	
	}
	else if(i==3)
    {
    printf("\n ENTER the values of Process id , BT , Priority for %drd Process :\n ",i);	
	}
	else
	{
	printf("\n ENTER the values of Process id , BT , Priority for %dth Process :\n ",i);
	}
	
  	printf("\n\t Process ID : ");
  	scanf("%d",&obj.pid);
  	
  	printf("\t Burst Time : ");
  	scanf("%d",&obj.bt);
  	
  	PRIOR:
  	
  	printf("\t Priority   : ");
  	scanf("%d",&obj.prior);
  	
  	if(obj.prior>=1 && obj.prior<=10)        // Giving prior Range For FIRST COME FIRST SERVE ALGO.
  	{
  		q3[p++]=obj; 
		n3+=1;
		sleep(1);
		printf("\n Process P%d Entered in Q3 \n",obj.pid);
		sleep(1);
	}
	
	else if(obj.prior>=11 && obj.prior<=20)   // Giving prior Range For prior ALGO.
  	{
  		q2[q++]=obj; 
		n2+=1;
		sleep(1);
		printf("\n Process P%d Entered in Q2 \n",obj.pid);
		sleep(1);
	}
	
	else if(obj.prior>=21 && obj.prior<=30)   // Giving prior Range For ROUND ROBIN ALGO.
  	{
  		q1[r++]=obj; 
		n1+=1;
		sleep(1);
		printf("\n Process P%d Entered in Q1 \n",obj.pid);
		sleep(1);
	}
	
    else
    {
    	printf("\n!!!!!!!!!!! PRIORITY ENTERED IS OUT OF RANGE !!!!!!!!!!!!!!\n");
  		goto PRIOR;
	}
		
  }
  
    printf("\n===============================================================================\n");
    // Calculating the Total Remaining Time in all the Queues
    
    printf("\nCalculating the Total Remaining Time in all the Queues : \n");
    
    int num1=0,num2=0,num3=0;
    
    for (int i=1;i<=n1;i++)
    {
     num1+=q1[i].bt; q1[i].wt=0;
	}
	printf(" \n\t Total Remaining Time in Q1 is: %d\n",num1);
	
	for (int i=1;i<=n2;i++)
    {
     num2+=q2[i].bt; q2[i].wt=0;
	}
	printf("\n\t Total Remaining Time in Q2 is: %d\n",num2);
	
	for (int i=1;i<=n3;i++)
    {
     num3+=q3[i].bt; q3[i].wt=0;
	}
	printf("\n\t Total Remaining Time in Q3 is: %d\n",num3);
	
	int Rem_bt[3];
    Rem_bt[1]=num1; Rem_bt[2]=num2; Rem_bt[3]=num3;
    
    int count=0;            // It is used for OUTER Roud Robin Algo. to Traverse the Queues after 10 sec
    
    int rem1_bt[n1] , rem2_bt[n2] , rem3_bt[n3] ;
    
    for (int i=1;i<=n1;i++)     // Paatitioning the Remaining Time by Each Process in Q1
        rem1_bt[i]=q1[i].bt;
        
    for (int i=1;i<=n2;i++)     // Paatitioning the Remaining Time by Each Process in Q1
        rem2_bt[i]=q2[i].bt;
        
    for (int i=1;i<=n3;i++)     // Paatitioning the Remaining Time by Each Process in Q1
        rem3_bt[i]=q3[i].bt;
        
     // Sorting all the processes in q2 based on their prior using Bubble Sort
     
	struct Table temp;  // Creating an object for Structure Table
	
	for(i=1;i<=n2;i++)
   	{
      	pos1=i;
        for(r1=i+1;r1<=n2;r1++)
        	{
            	if(q2[r1].prior>q2[pos1].prior)
                pos1=r;
        	}
        temp=q2[i];
        q2[i]=q2[pos1];
        q2[pos1]=temp;
    }
     
    while(1) // Outer Round Robin while loop
    {
        bool Finish=true;   
        
        for (int k=1;k<=3;k++) // Traversing Three Queues
        {
		  count=0;
		  
		  if(Rem_bt[k]>0)
		  { 
		    Finish=false ; // Queue is Pending to process  
		    
            //======= Processing on Traversing the Queue after 10 sec and on Remaining BT of Outer RR ==========
            
			if(Rem_bt[k]>Q)
			{
			  if(k==1&&n1!=0) // Q1 RR Starts with with Highest priority
			  {
        		  
    			 t+=c1; // Current time
                 count=0;
                 
   				 while(1)    // Inner RR while loop
    			 {
      			  bool Finish=true;
        		  for (int i=1;i<=n1;i++) // Traversing each process of Q1
       			   {
             		if (rem1_bt[i]>0)
            		 {
                			Finish=false; // There Exist a Pending Process in Q1
 
                		    if (rem1_bt[i]>Q1)
                		    {
                  				if(count+Q1>10)
                  				{
                  					rem1_bt[i]-=10-count; 
									t+=10-count ; 
									count=10;
								    break;
								  }
								t+=Q1; 
								count+=Q1;
                    			rem1_bt[i]-=Q1;
                    			  
                			 }
                			else
                			{
                				if(count+q1[i].bt>10)
                  				{
                  					rem1_bt[i]-=10-count;
									t+=10-count;  
									count=10;
									break; 
								}
                    			t=t+rem1_bt[i];
                    			q1[i].wt+=t-q1[i].bt;  
								count+=q1[i].bt;
                    			rem1_bt[i]=0;
                	      	}
            		  }
            		  if(count>=10)
            		   {
            		     break; 
					   }
        		     }
                     if (Finish==true||count>=10)
                        break;
                    } 
			        // End of Inner RR while loop
			        
 					printf("\nWaiting time is:%d\n",q1[i].wt) ;
 					Rem_bt[k]-=Q; 
 					c1=0;
					c2+=Q;
					c3+=Q;
 					
				 } // End of Q1 Highest Priority
               	
			  
			  else if(k==2 && n2!=0)  // Q2 Starting Priority Algorithm
				{
                 // Calculating Waiting Time in Q2 for all Processes
                 
     			   count=0;
        		   for(i=1;i<=n2;i++)
        		   {
        		       if(rem2_bt[i]<=0&&rem2_bt[i+1]<=0) 
        		       {
        		       	 continue;
					   }
					   else if(rem2_bt[i]<=0&&rem2_bt[i+1]>0) 
        		       { 
							q2[i+1].wt+=q2[i].bt+q2[i].wt+c2;
							continue;
					   }
					    q2[i].wt+=c2;
					     
					   while(rem2_bt[i]!=0)
					   {
					       if(count==10)
					       break;
						   rem2_bt[i]-=1;
					       count++;
						}				   
					   if(count>10)
					      break;
					    if(i==n2)
					    {
					      break;	
						}
						if(rem2_bt[i]==0)
						{
							q2[i+1].wt=q2[i].bt+q2[i].wt;
						}
				     }
				     // printf("\nhWaiting time is:%d\n",q2[i].wt) ;

                   Rem_bt[k]-=Q;
                   c2=0; 
                   c1+=Q;
				   c3+=Q;
		          }  // End of Q2  
			   
              else if(k==3&&n3!=0)  // Q3 Starting FCFS Algorithm
				{
                 //Calculating Waiting Time in Q3 for all Processes
     			   count=0;
        		   for(i=1;i<=n3;i++)
        		   {
        		       if(rem3_bt[i]<=0&&rem3_bt[i+1]<=0) 
        		       {
        		       	 continue;
					   }
					   else if(rem3_bt[i]<=0&&rem3_bt[i+1]>0) 
        		       {
							 q3[i+1].wt+=q3[i].bt+q3[i].wt+c3;
							 continue;
					   }
					   q3[i].wt+=c3 ;
					   while(rem3_bt[i]!=0)
					   {
					       if(count==10)
					        break;
						   rem3_bt[i]-=1;
					       count+=1;
						}				   
					    if(count>10)
					        break;
					    if(i==n3)
					    {
					      break;	
						}
						if(rem3_bt[i]==0)
						{
					    q3[i+1].wt=q3[i].bt+q3[i].wt;
					    }
				     }
					printf("\nhWaiting time is:%d\n",q3[i].wt) ;
                   Rem_bt[k]-=Q; 
                   c1+=Q;
				   c2+=Q;
				   c3=0;
		          }  // End of Q3
		          
              }//end of iF-Rem_bt[k]>Q1
   		    
                          //============= End of Outer RR Remaining Time ============
         
         else
		 { 
		   if(k==1&&n1!=0)  // Q1
		   {  
    			t+=c1;  	
		    	while (1)
    			{
        			bool Finish=true;
        			for (int i=1;i<=n1;i++) // To Traverse Each Process in Q1
        			{

           			 	if (rem1_bt[i]>0)
            			{
                			Finish=false; // There Exist a Pending Process in Q1
                			if (rem1_bt[i]>Q1)
                				{
                    				t+=Q1;
                    				rem1_bt[i]-=Q1;
                				}
                			else
                				{
                    				t=t+rem1_bt[i];
                    				q1[i].wt=t-q1[i].bt;
                    				rem1_bt[i]=0;
                				}
            			}
        			}
        			if(Finish==true)
          			   break;
    			}
		    	c1=0;
				c2+=Rem_bt[k];
				c3+= Rem_bt[k];
		    	Rem_bt[k]=0;		       
		      } // End of Q1.
		      
		  else if(k==2&&n2!=0)  // Q2
		  {
		  	 for(i=1;i<=n2;i++)
        		   {
        		       if(i==1&&n2==1)
					    {
					    	q2[i].wt+=c2;
							rem2_bt[k]=0;
							break;
						}
						if(i==n2)
						{
							rem2_bt[i]=0;
							break;
						}
					   if(rem2_bt[i]<=0&&rem2_bt[i+1]<=0) 
        		       {
        		       	 continue;
					   }
					   else if(rem2_bt[i]<=0&&rem2_bt[i+1]>0) 
        		       {
							 q2[i+1].wt=q2[i].bt+q2[i].wt+c2;
							 continue; 
					   }
					     q2[i].wt+=c2;
					     rem2_bt[i]=0;
					     q2[i+1].wt=q2[i].bt+q2[i].wt;
				    }
			 c2=0; 
			 c3+=Rem_bt[k];
			 c1+= Rem_bt[k];
			 Rem_bt[k]=0;
		   } // End of Q2
		   
		   else if(k==3&&n3!=0)  // Q3 
		  {
		  	 for(i=1;i<=n3;i++)
        		   {
        		       if(i==1&&n3==1)
					    {
					    	q3[i].wt+=c3;
							rem3_bt[k]=0;
							break;
						}
						if(i==n3)
						{
							rem3_bt[i]=0;
							break;
						}
					   if(rem3_bt[i]<=0&&rem3_bt[i+1]<=0) 
        		       {
        		       	 continue;
					   }
					   else if(rem3_bt[i]<=0&&rem3_bt[i+1]>0) 
        		       {
							 q3[i+1].wt=q3[i].bt+q3[i].wt+c3;
							 continue; 
					   }
					     q3[i].wt+=c3;
					     rem3_bt[i]=0;
					       	
					     q3[i+1].wt=q3[i].bt+q3[i].wt;
				    }
			 c3=0;
			 c2+=Rem_bt[k];
			 c1+= Rem_bt[k];
			 Rem_bt[k]=0;
		   } // End of Q3
		 	
		}  //End of else loop Rem_bt[k]>Q1 
       
            
	   } //End of loop Rem_bt[k]>0
      
	} // End of Queues Traversing Loop

		if (Finish==true)
            break;
  }  //  End of Outer Round Robin
  
 // ==============Calculating Turn Around Time (TAT) for Q1,Q2,Q3==================

int wt_sum=0,tat_sum=0;

 for(int i=1;i<=n1;i++)  // For Q1
   { 
      q1[i].tat=q1[i].bt+q1[i].wt;
      wt_sum+=q1[i].wt;
	  tat_sum+=q1[i].tat; 
   }
   
 for(int i=1;i<=n2;i++)  // For Q2
   { 
      q2[i].tat=q2[i].bt+q2[i].wt;
      wt_sum+=q2[i].wt;
	  tat_sum+=q2[i].tat;  
   }
   
 for(int i=1;i<=n3;i++)  // For Q3
  { 
      q3[i].tat=q3[i].bt+q3[i].wt;
      wt_sum+=q3[i].wt;
	  tat_sum+=q3[i].tat;  
  }
 
// Printing the Table which contains Queues and attached with their processes and values of BT , prior , WT , TAT (Total Around Time)

printf("\n\t====================TABLE AFTER CALCULATING THE VALUES OF W.T AND T.A.T====================\n");

printf(" \n PROCESS NO. \t     PRIORITY \t  BURST TIME \t WAITING TIME \t TURN AROUND TIME");

printf("\n\n(Q1) : \n");
 for (int i=1;i<=n1;i++)
 {
	printf("\n    P%d  \t\t%d \t\t%d \t\t%d \t\t%d\n",q1[i].pid,q1[i].prior,q1[i].bt,q1[i].wt,q1[i].tat);
 }

printf("\n(Q2) : \n");

 for (int i=1;i<=n2;i++)
 {
	printf("\n     P%d  \t\t%d \t\t%d \t\t%d \t\t%d\n",q2[i].pid,q2[i].prior,q2[i].bt,q2[i].wt,q2[i].tat);
 }

printf("\n(Q3) : \n");

 for (int i=1;i<=n3;i++)
 {
	printf("\n     P%d \t\t%d \t\t%d \t\t%d \t\t%d\n",q3[i].pid,q3[i].prior,q3[i].bt,q3[i].wt,q3[i].tat);
 }
 
printf("\n");
printf("\n\n\t***************************** THE END ****************************\n\n");
}
