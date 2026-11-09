/**
 * ============================================================================
 * CONTENT SCRIPT — content.js
 * ============================================================================
 * This is a "content script". Chrome injects it into pages that match the
 * URL patterns defined in manifest.json (all youtube.com URLs).
 * Content scripts run in the context of the web page and can access:
 *   • The DOM (document.querySelector, event listeners, etc.)
 *   • Any <video> element on the page
 * They cannot directly call Chrome Extension APIs (like chrome.tabs or
 * chrome.runtime) — those are only available in background scripts and
 * extension pages (popup, options).
 * ============================================================================

// ----------------------------------------------------------------------------
// 1. Small German → English dictionary (for demo purposes)
// ----------------------------------------------------------------------------
const DICTIONARY = {
  "die":        "the",
  "der":        "the",
  "das":        "the",
  "und":        "and",
  "ist":        "is",
  "ich":        "I",
  "du":         "you",
  "sie":        "she / they",
  "wir":        "we",
  "haben":      "to have",
  "sein":       "to be",
  "geht":       "goes / walks",
  "kommen":     "to come",
  "machen":     "to do / to make",
  "sprechen":   "to speak",
  "deutsch":    "German",
  "englisch":   "English",
  "Wort":       "word",
  "Buch":       "book",
  "Haus":       "house",
  "Auto":       "car",
  "Freund":     "friend",
  "Tag":        "day",
  "Nacht":      "night",
  "Guten":      "Good",
  "Tag":        "day / good day",
  "Morgen":     "morning / tomorrow",
  "Abend":      "evening",
  "Ja":         "yes",
  "Nein":       "no",
  "Bitte":      "please / you're welcome",
  "Danke":      "thank you",
  "Entschuldigung": "excuse me / sorry",
  "Wasser":     "water",
  "Brot":       "bread",
  "Apfel":      "apple",
  "Katze":      "cat",
  "Hund":       "dog",
};

// Helper: look up a German word and return its English translation.
// Returns null if the word is not in our dictionary.
function translateWord(word) {
  const cleaned = word.replace(/[.,!?;:'"()]*/g, "").toLowerCase();
  const translation = DICTIONARY[cleaned];
  return translation !== undefined ? translation : null;
}

// ----------------------------------------------------------------------------
// 2. Tooltip element (the little box that shows the translation)
// ----------------------------------------------------------------------------
let tooltip = null;

function ensureTooltip() {
  if (tooltip) return tooltip;
  tooltip = document.createElement("div");
  tooltip.id = "de-en-translator-tooltip";
  Object.assign(tooltip.style, {
    position: "fixed",
    zIndex:   999999,
    padding:  "6px 10px",
    background: "#fff3cd",
    border:   "1px solid #ffc107",
    borderRadius: "4px",
    color:    "#000",
    fontSize: "14px",
    fontFamily: "Arial, sans-serif",
    pointerEvents: "none",
    whiteSpace: "nowrap",
    boxShadow: "0 2px 6px rgba(0,0,0,0.2)",
    display:  "none",
  });
  document.body.appendChild(tooltip);
  return tooltip;
}

function showTooltip(text, x, y) {
  if (!tooltip) ensureTooltip();
  tooltip.textContent = text;
  tooltip.style.display = "block";
  tooltip.style.left = (x + 12) + "px";
  tooltip.style.top  = (y + 12) + "px";
}

function hideTooltip() {
  if (tooltip) tooltip.style.display = "none";
}

// ----------------------------------------------------------------------------
// 3. Video control helpers
// ----------------------------------------------------------------------------
function pauseVideo() {
  const video = document.querySelector("video");
  if (video && !video.paused) {
    video.pause();
  }
}

function resumeVideo() {
  // Resume on mouse-out if you want automatic resume.
  // We deliberately do NOT resume here so the learner can read the tooltip.
}

// ----------------------------------------------------------------------------
// 4. Caption detection
// ----------------------------------------------------------------------------
function isCaptionElement(el) {
  let node = el;
  while (node && node.nodeType === Node.ELEMENT_NODE) {
    const cls = node.className || "";
    if (/caption|subtitle|ytp-caption|captions/i.test(cls)) {
      return true;
    }
    node = node.parentElement;
  }
  return false;
}

// ----------------------------------------------------------------------------
// 5. Event handlers
// ----------------------------------------------------------------------------
function onMouseOver(event) {
  const target = event.target;
  if (!isCaptionElement(target)) return;
  const text = target.textContent ? target.textContent.trim() : "";
  if (!text) return;
  const translation = translateWord(text);
  if (!translation) return;
  pauseVideo();
  showTooltip(`${text} → ${translation}`, event.clientX, event.clientY);
}

function onMouseOut(event) {
  hideTooltip();
}

// ----------------------------------------------------------------------------
// 6. Attach listeners (capture phase)
// ----------------------------------------------------------------------------
document.addEventListener("mouseover", onMouseOver, true);
document.addEventListener("mouseout",  onMouseOut,  true);

console.log("[YouTube DE-EN Translator] Content script loaded.");
