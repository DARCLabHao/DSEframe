import os

attr_cnt = 0;
def main():
    open('data_ave8.csv', 'w').close()
    attr_cnt = 0;
    with open("lib.info") as f:
	    lines = f.readlines()
    lines1 = [l for l in lines if "attr1" in l]
    lines2 = [l for l in lines if "attr2" in l]
    lines3 = [l for l in lines if "attr3" in l]
    for line1 in lines1:	
        for line2 in lines2:
            for line3 in lines3:
                data1 = line1.split()
                data2 = line2.split()
                data3 = line3.split()
                with open("attrs.h", "w") as fh:
                    fh.write("#define ATTR1 Cyber " + data1[1] + "=" + data1[2] + "\n")
                    fh.write("#define ATTR2 Cyber " + data2[1] + "=" + data2[2] + "\n")
                    fh.write("#define ATTR3 Cyber " + data3[1] + "=" + data3[2] + "\n")
                attr_cnt = attr_cnt + 1
                hls()
	
def hls():
    ret_val = os.system("bdlpars -EE -I.  -I/proj/cad/cwb-6.1/linux_x86_64/include  -info_base_name ave8  './ave8.c'");
    ret_val = os.system("bdltran  -EE   -c1000 -s -Zresource_fcnt=GENERATE -Zresource_mcnt=GENERATE -Zdup_reset=YES -Zfolding_sharing=inter_stage -EE -lb /proj/cad/cwb-6.1/packages/asic_45.BLIB -lfl /proj/cad/cwb-6.1/packages/asic_45.FLIB ave8.IFF");
    if ret_val == 0:
        with open('ave8.CSV','r') as f:
            f_data = f.readlines()

        with open('data_ave8.csv', 'a') as fa:
            if os.path.getsize('data_ave8.csv') == 0:
                fa.write("Method,Iteration,ATTR," + f_data[0])
            fa.write("BF,1," + str(attr_cnt) + "," + f_data[1])

if __name__ == "__main__":
    main()
