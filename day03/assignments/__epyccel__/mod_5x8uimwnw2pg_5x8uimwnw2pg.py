def cavity_flow_cel(nt:'int', u:'float[:,:]', v:'float[:,:]', dt:'float', nx:'int', ny:'int', dx:'float', dy:'float', p:'float[:,:]', rho:'float', nu:'float'):
    
    import numpy as np
    
    rowu, colu = u.shape
    rowv, colv = v.shape
    
    un = [[0 for i in range(rowu)] for j in range(colu)]
    vn = [[0 for i in range(rowv)] for j in range(colv)]
    b = [[0 for i in range(nx)] for j in range(ny)]
    
    un = np.array(un)
    vn = np.array(vn)
    b = np.array(b)
    
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
