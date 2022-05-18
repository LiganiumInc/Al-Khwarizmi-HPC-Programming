def solve_2d_diff_pyccel(u:'float[:,:]', un:'float[:,:]', nt:'int', dt:'float', dx:'float', dy:'float', nu:'float'):
    row, col = u.shape
    
    ##Assign initial conditions
    #set hat function I.C. : u(.5<=x<=1 && .5<=y<=1 ) is 2
    u[int(.5 / dy):int(1 / dy + 1),int(.5 / dx):int(1 / dx + 1)] = 2
    
    
    #fill the update of u and v
    for n in range(nt+1):  
        for i in range(row):
            for j in range(col):
                un[i,j] = u[i,j]
        
        u[1:-1, 1:-1] = un[1:-1,1:-1] + nu*dt/dx**2 * \
        (un[2:,1:-1]-2*un[1:-1,1:-1]+un[0:-2,1:-1]) +\
        nu*dt/dy**2*(un[1:-1,2:]-2*un[1:-1,1:-1]+un[1:-1,0:-2])
        
        u[0,:] = 1
        u[-1,:] =1
        u[:,0] = 1
        u[:,-1] = 1
        
    return 0
