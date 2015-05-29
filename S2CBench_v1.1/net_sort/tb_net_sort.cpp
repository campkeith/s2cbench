#include "tb_net_sort.h"


//--------------------------
// Send data thread
//-------------------------
void test_net_sort::send(){

    in_file = fopen(INFILENAME, "rt");
    if (!in_file)
    {
        perror(INFILENAME);
        sc_stop();
    }

    for (size_t index = 0; index < SIZE; index++)
    {
        indata[index].write(0);
    }
    wait();

    while (true)
    {
        for (size_t index = 0; index < SIZE; index++)
        {
            int element;
            int result = fscanf(in_file, "%d", &element);
            if (result == EOF)
            {
                assert(index == 0);
                goto exit_loop;
            }
            indata[index].write(element);
        }
        wait();
    }
exit_loop:

    fclose(in_file);
    cout << endl << "Starting comparing results " << endl;
    compare_results();
    sc_stop();
}



//--------------------------
// Receive data thread
//--------------------------
void test_net_sort::recv(){

    out_file = fopen (OUTFILENAME, "wt");
    if (!out_file) {
        perror(OUTFILENAME);
        sc_stop();
    }
    wait();

    while (true)
    {
        for (size_t index = 0; index < SIZE; index++) {
            int element = odata[index].read();
            fprintf(out_file, "%3d ", element);
        }
        fprintf(out_file, "\n");
        wait();
    }
}


//--------------------------
// Compare results function
//--------------------------
void test_net_sort::compare_results(){

  int outsort, out_golden, line=1, errors=0;

  // Close file where outputs are stored
  fclose(out_file);

  out_file = fopen (OUTFILENAME, "rt");

  if(!out_file){
    cout << "Could not open " << OUTFILENAME << "\n";
    sc_stop();
    exit(EXIT_FAILURE);
  }

    //
    //Load the golden pattern
    //
      out_golden_file = fopen (OUTFILENAME_GOLDEN, "rt");
     if(!out_golden_file){
      cout << "Could not open " << OUTFILENAME_GOLDEN << "\n";
      sc_stop();
      exit(EXIT_FAILURE);
     }

    //
    //Dump the comparison result
    //
    diff_file = fopen (DIFFFILENAME, "w");
    if(!diff_file){
	 cout << "Could not open " << DIFFFILENAME<< "\n";
	 sc_stop();
       }

    while(fscanf(out_golden_file, "%d", &out_golden) != EOF){
      fscanf(out_file,"%d", &outsort);
     

      cout << endl <<"Cycle["<< line << "]: " << out_golden << "-- "<< outsort;

      if(outsort != out_golden){
	cout << "\nOutput missmatch [line:" << line << "] Golden:" << out_golden << " -- Output:" << outsort;

	fprintf(diff_file,"\nOutput missmatch[line:%d] Golden: %d -- Output: %d",line, out_golden, outsort);
	
	errors++;
      }
      
      line ++;

    }

    if(errors == 0)
      cout << endl << "Finished simulation SUCCESSFULLY" << endl;
    else
      cout << endl << "Finished simulation " << errors << " MISSMATCHES between Golden and Simulation" << endl;


    fclose(out_file);
    fclose(diff_file);
    fclose(out_golden_file);



}

