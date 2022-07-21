import React from "react";

const onclick = () =>{
    console.log('this is my creating button')
} 

const CreateNewPostButton = () => {
    return(
        <>
    <button type="button" className="btn btn-primary" onClick={onclick()}>Post</button>
    </>
    )
}
export default CreateNewPostButton