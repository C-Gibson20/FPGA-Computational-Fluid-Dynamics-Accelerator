for i in ["0","n","ne","e","se","s","sw","w","nw"]:
    s = f"""c{i}_addr,
c{i}_data_in, 
c{i}_write_en,
c{i}_data_out,
init_c{i},"""
    print(s)