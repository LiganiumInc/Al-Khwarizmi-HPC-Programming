def cavity_flow_cel(nt:'int', u:'float[:,:]', v:'float[:,:]', dt:'float', nx:'int', ny:'int', dx:'float', dy:'float', p:'float[:,:]', rho:'float', nu:'float'):
    
    import numpy as np
    
    rowu, colu = u.shape
    rowv, colv = v.shape
    
    ua = []
    for i in range(rowu):
        ua1 = []
        for j in range(colu):
            ua1.append(0)
        ua.append(ua1)
            
    va = []
    for i in range(rowv):
        va1 = []
        for j in range(colv):
            va1.append(0)
        va.append(va1)
    
    ba = []
    for i in range(row):
        ba1 = []
        for j in range(col):
            ba1.append(0)
        ba.append(ba1)
        
#     ua = [[0 for i in range(rowu)] for j in range(colu)]
#     va = [[0 for i in range(rowv)] for j in range(colv)]
#     ba = [[0 for i in range(nx)] for j in range(ny)]
    
    un = np.array(ua)
    vn = np.array(va)
    b = np.array(ba)
    
    for n in range(nt):

        for i in range(rowu):
            for j in range(colu):
                un[i,j] = u[i,j]
        
        for i in range(rowv):
            for j in range(colv):
                vn[i,j] = v[i,j]
        
        from pyccel.epyccel import epyccel 
        
        bb_cel = epyccel(build_up_b_cel)
        pp_cel = epyccel(pressure_poisson_cel)
        
        b = bb_cel(b, rho, dt, u, v, dx, dy)
        p = pp_cel(p, dx, dy, b)
        
        u[1:-1, 1:-1] = (un[1:-1, 1:-1]-
                         un[1:-1, 1:-1] * dt / dx *
                        (un[1:-1, 1:-1] - un[1:-1, 0:-2]) -
                         vn[1:-1, 1:-1] * dt / dy *
                        (un[1:-1, 1:-1] - un[0:-2, 1:-1]) -
                         dt / (2 * rho * dx) * (p[1:-1, 2:] - p[1:-1, 0:-2]) +
                         nu * (dt / dx**2 *
                        (un[1:-1, 2:] - 2 * un[1:-1, 1:-1] + un[1:-1, 0:-2]) +
                         dt / dy**2 *
                        (un[2:, 1:-1] - 2 * un[1:-1, 1:-1] + un[0:-2, 1:-1])))

        v[1:-1,1:-1] = (vn[1:-1, 1:-1] -
                        un[1:-1, 1:-1] * dt / dx *
                       (vn[1:-1, 1:-1] - vn[1:-1, 0:-2]) -
                        vn[1:-1, 1:-1] * dt / dy *
                       (vn[1:-1, 1:-1] - vn[0:-2, 1:-1]) -
                        dt / (2 * rho * dy) * (p[2:, 1:-1] - p[0:-2, 1:-1]) +
                        nu * (dt / dx**2 *
                       (vn[1:-1, 2:] - 2 * vn[1:-1, 1:-1] + vn[1:-1, 0:-2]) +
                        dt / dy**2 *
                       (vn[2:, 1:-1] - 2 * vn[1:-1, 1:-1] + vn[0:-2, 1:-1])))
        
        u[0, :]  = 0
        u[:, 0]  = 0
        u[:, -1] = 0
        u[-1, :] = 1    # set velocity on cavity lid equal to 1
        v[0, :]  = 0
        v[-1, :] = 0
        v[:, 0]  = 0
        v[:, -1] = 0

    return u, v, p
