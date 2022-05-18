def solve_2d_linearconv_pyccel(u:'float[:,:]', un:'float[:,:]', nt:int, dt:float, dx:float, dy:float, c:int):
   
    row, col = u.shape

    #fill the update of u and v
    for n in range(nt+1):
        
        for i in range(row):
            for j in range(col):
                un[i,j] = u[i,j]
        
        for i in range(1,row):
            for j in range(1,col):
                u[i,j] = un[i,j] -c*dt/dx *(un[i,j]-un[i-1,j])-\
                c*dt/dy*(un[i,j]-un[i,j-1])
                u[0,:]=1
                u[-1,:]=1
                u[:,0]=1
                u[:,-1]=1
    
    return 0
