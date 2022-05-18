def solve_2d_nonlinearconv_pyccel(u:'float[:,:]', un:'float[:,:]', v:'float[:,:]', vn:'float[:,:]', nt:'int', dt:'float', dx:'float', dy:'float', c:'int'):

    ###Assign initial conditions
    ##set hat function I.C. : u(.5<=x<=1 && .5<=y<=1 ) is 2
    u[int(.5 / dy):int(1 / dy + 1), int(.5 / dx):int(1 / dx + 1)] = 2
    ##set hat function I.C. : v(.5<=x<=1 && .5<=y<=1 ) is 2
    v[int(.5 / dy):int(1 / dy + 1), int(.5 / dx):int(1 / dx + 1)] = 2
    row, col = u.shape
    
    #fill the update of u and v
    for n in range(nt+1):  
        
        for i in range(row):
            for j in range(col):
                un[i,j] = u[i,j]
                
        u[1:,1:] = un[1:,1:] - un[1:,1:] * dt/dx * (un[1:,1:]-un[0:-1,1:])\
        -vn[1:,1:] * dt/dy * (un[1:,1:] - un[1:,0:-1])
        
        v[1:,1:] = vn[1:,1:] - un[1:,1:] * dt/dx * (vn[1:,1:] -vn[0:-1,1:])\
        -vn[1:,1:] * dt/dy * (vn[1:,1:] - vn[1:,0:-1])
        
        u[0,:] =1 
        u[-1,:] = 1
        u[:,0] = 1
        u[:,-1] = 1
        
        v[0,:] =1 
        v[-1,:] = 1
        v[:,0] = 1
        v[:,-1] = 1
        
    return 0
