import React from 'react'
import axios from 'axios';

const Blogs = () =>{

    return(
        <>        
        <div>My Blogs</div>
        <div className="card" style={{ width: '18rem' }}>
        <div className="card-body">
        <h5 className="card-title">REACT APP</h5>
        <p className="card-text">We gotta learn to create our first react app</p>
        <a href="#" className="btn btn-primary">Let's Go!</a>
      </div>
    </div>
    
    </>

    )
}

export default Blogs