def pressure_poisson_cel(p:'float[:,:]', dx:'float', dy:'float', b:'float[:,:]', nit:'int'):
    
    import numpy as np
    
    pn = np.empty_like(p)
    row , col = p.shape
    
    
#     pn = np.empty_like(p)
    
    for i in range(row):
            for j in range(col):
                pn[i,j] = p[i,j]
    
    #fill the update of p
    for q in range(nit):

        for i in range(row):
            for j in range(col):
                pn[i,j] = p[i,j]
                
        p[1:-1, 1:-1] = (((pn[1:-1, 2:] + pn[1:-1, 0:-2]) * dy**2 + 
                          (pn[2:, 1:-1] + pn[0:-2, 1:-1]) * dx**2) /
                          (2 * (dx**2 + dy**2)) -
                          dx**2 * dy**2 / (2 * (dx**2 + dy**2)) * 
                          b[1:-1,1:-1])

        p[:, -1] = p[:, -2] # dp/dx = 0 at x = 2
        p[0, :] = p[1, :]   # dp/dy = 0 at y = 0
        p[:, 0] = p[:, 1]   # dp/dx = 0 at x = 0
        p[-1, :] = 0        # p = 0 at y = 2
