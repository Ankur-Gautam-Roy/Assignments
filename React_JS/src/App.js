import './App.css';
import Blogs from './components/Blogs'
import CreateNewPostButton from './components/CreateNewPostButton'
function App() {
  return (
    <div className="App">
      <h1>BLOGMASTER</h1>
      <Blogs/>
      <CreateNewPostButton />
      </div>
      
  );
}

export default App;
