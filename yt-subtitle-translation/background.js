/**
 * ============================================================================
 * BACKGROUND SERVICE WORKER — background.js
 * ============================================================================
 * In Manifest V3, background scripts run as "service workers".
 * They are event-driven: they start when needed, handle an event, then
 * may be shut down by the browser to save memory.
 *
 * Unlike content scripts, background scripts CAN use Chrome Extension APIs:
 *   chrome.runtime, chrome.tabs, chrome.storage, chrome.action, etc.
 *
 * For THIS simple extension we don't strictly NEED a background script,
 * because all the logic (pause video, show tooltip) lives in the content
 * script. We include this file anyway for educational purposes and to
 * demonstrate the standard extension structure.
 * ============================================================================

console.log("[YouTube DE-EN Translator] Background service worker started.");

// Example: Listen for the extension icon being clicked.
// This would open a popup, but we didn't define one in manifest.json.
// Uncomment and add a "default_popup" in manifest.json if you want a UI.
/*
chrome.action.onClicked.addListener((tab) => {
  console.log("Extension icon clicked on tab:", tab.id);
});
*/

// Example: Listen for messages from the content script.
// This is how content scripts can communicate with the background.
// We don't use it here, but it's a fundamental pattern.
/*
chrome.runtime.onMessage.addListener((message, sender, sendResponse) => {
  if (message.type === "GET_TRANSLATION") {
    // Could look up in a larger dictionary stored in chrome.storage
    sendResponse({ translation: "TODO" });
  }
});
*/

// Example: Store user preferences in chrome.storage.sync.
// This persists across browser sessions and syncs across devices.
/*
chrome.storage.sync.get(["autoPause"], (result) => {
  console.log("Auto-pause setting:", result.autoPause);
});
*/

// The service worker will stay alive as long as there are active event
// listeners or ongoing async operations. When idle, Chrome may terminate it.
// It will be restarted automatically when the next event fires.
