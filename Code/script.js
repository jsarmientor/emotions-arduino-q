const video = document.getElementById('video');
const currentExpressionSpan = document.getElementById('current-expression');

// Mapping of face-api.js expressions to UI text and emojis
const expressionsMap = {
    happy: { emoji: '😃', text: 'Happy', btnId: 'btn-happy' },
    sad: { emoji: '😢', text: 'Sad', btnId: 'btn-sad' },
    neutral: { emoji: '😐', text: 'Neutral', btnId: 'btn-neutral' },
    angry: { emoji: '😡', text: 'Angry', btnId: 'btn-angry' },
    surprised: { emoji: '😲', text: 'Surprised', btnId: null },
    disgusted: { emoji: '🤢', text: 'Disgusted', btnId: null },
    fearful: { emoji: '😨', text: 'Fearful', btnId: null }
};

// Load face-api models
async function loadModels() {
    try {
        currentExpressionSpan.innerText = "Loading models...";
        await Promise.all([
            faceapi.nets.tinyFaceDetector.loadFromUri('./models'),
            faceapi.nets.faceExpressionNet.loadFromUri('./models')
        ]);
        currentExpressionSpan.innerText = "Starting camera...";
        startVideo();
    } catch (e) {
        console.error("Error loading models:", e);
        currentExpressionSpan.innerText = "Error loading models. (Make sure to run with a local server)";
    }
}

// Start webcam
function startVideo() {
    navigator.mediaDevices.getUserMedia({ video: { width: 640, height: 480 } })
        .then(stream => {
            video.srcObject = stream;
        })
        .catch(err => {
            console.error("Error accessing camera:", err);
            currentExpressionSpan.innerText = "No camera access";
        });
}

let lastExpression = null;
let noFaceFrames = 0;

// Listen for video play event
video.addEventListener('play', () => {
    currentExpressionSpan.innerText = "Detecting...";
    
    // Detection interval
    setInterval(async () => {
        // Detect faces and expressions using TinyFaceDetector for performance
        const detections = await faceapi.detectAllFaces(video, new faceapi.TinyFaceDetectorOptions()).withFaceExpressions();
        
        if (detections.length > 0) {
            noFaceFrames = 0; // Reset loss counter
            const expressions = detections[0].expressions;
            
            // Get the dominant expression (highest probability)
            const dominant = Object.keys(expressions).reduce((a, b) => expressions[a] > expressions[b] ? a : b);
            
            // Only update the UI if there is a real change to avoid flickering
            if (dominant !== lastExpression) {
                lastExpression = dominant;
                updateUI(dominant);
                
                // Arduino integration: Call sendEmotion if defined
                if (typeof sendEmotion === 'function') {
                    const allowedEmotions = ['happy', 'sad', 'neutral', 'angry'];
                    if (allowedEmotions.includes(dominant)) {
                        sendEmotion(dominant);
                    }
                }
            }
        } else {
            // Wait ~1.5s before clearing detection state
            noFaceFrames++;
            if (noFaceFrames > 3) {
                sendEmotion('unknown');
                lastExpression = null;
                currentExpressionSpan.innerText = "No face detected";
                document.querySelectorAll('.exp-btn').forEach(btn => btn.classList.remove('active'));
            }
        }
    }, 50); 
});

// Update UI with detected expression
function updateUI(expression) {
    const mappedData = expressionsMap[expression];
    
    if (mappedData) {
        currentExpressionSpan.innerText = mappedData.text;
        
        // Update button states
        document.querySelectorAll('.exp-btn').forEach(btn => btn.classList.remove('active'));
        if (mappedData.btnId) {
            const btn = document.getElementById(mappedData.btnId);
            if (btn) btn.classList.add('active');
        }
    }
}

// Initialize
loadModels();


// Iniciar proceso
loadModels();
